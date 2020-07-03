//
// Created by oke on 01.07.20.
//

#ifndef SMID_MATRIX_REGISTERBLOCKING_H
#define SMID_MATRIX_REGISTERBLOCKING_H

#include "Matrix.h"
#include <immintrin.h>

struct __m256_block_wise_config {
    using FloatType = float;
    using VectorType = __m256;
    static constexpr auto LoadVector = _mm256_loadu_ps;
    static constexpr auto StoreVector = _mm256_storeu_ps;
    static constexpr auto BroadcastToVector = _mm256_broadcast_ss;
};

struct __m256d_block_wise_config {
    using FloatType = double;
    using VectorType = __m256d;
    static constexpr auto LoadVector = _mm256_loadu_pd;
    static constexpr auto StoreVector = _mm256_storeu_pd;
    static constexpr auto BroadcastToVector = _mm256_broadcast_sd;
};

template<typename BlockWiseConfig>
struct ExtendedBlockWiseConfig {
    typedef typename BlockWiseConfig::FloatType FloatType;
    using VectorType = typename BlockWiseConfig::VectorType;
    static constexpr auto LoadVector = BlockWiseConfig::LoadVector;
    static constexpr auto StoreVector = BlockWiseConfig::StoreVector;
    static constexpr auto BroadcastToVector = BlockWiseConfig::BroadcastToVector;
    static constexpr size_t VectorWidth = sizeof(VectorType) / sizeof(FloatType);
    static constexpr auto AddAndStore = [](FloatType *memory, VectorType vector) { StoreVector(memory, LoadVector(memory) + vector); };
};
template<
        // template parameter as struct: otherwise some warning about losing alignment information warning
        typename BitWiseConfig,
        unsigned _NumRows, unsigned _NumColumnVectors
>
struct RegisterBlocking {
    typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

    static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
        bwc::StoreVector(memory, bwc::LoadVector(memory) + vector); };

    static constexpr auto NumRows = _NumRows;
    static constexpr auto NumColumns = _NumColumnVectors * bwc::VectorWidth;

    template<typename M1, typename M2, typename M3>
    static void __attribute__ ((noinline))  handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {

        // AVX2 has 16 registers
        // should be compiled as registers (total: regA * regB)
        typename bwc::VectorType CReg[_NumRows][_NumColumnVectors] = {{0.0}};
        // iterate over dot-product terms
        for (int p = 0; p < k; p++) { // row index in B and column index in A (handling all rows/columns)
            // Perform the DOT product
            for (int bi = 0; bi < _NumColumnVectors; bi++) { // column index in B (handling regsB * 'VectorWidth' columns)
                typename bwc::VectorType bb = bwc::LoadVector(&B(p, bColOffset + bi * bwc::VectorWidth));
                for (int ai = 0; ai < _NumRows; ai++) { // row index in A (handling regsA rows)
                    typename bwc::VectorType aa = bwc::BroadcastToVector(&A(aRowOffset + ai, p));
                    CReg[ai][bi] += aa * bb;
                }
            }
        }
        // total regA * regB + regB registers

        // Accumulate the results into C.
        for (int ai = 0; ai < _NumRows; ai++) {
            for (int bi = 0; bi < _NumColumnVectors; bi++) {
                AddAndStore(&C(aRowOffset + ai, bColOffset + bi * bwc::VectorWidth), CReg[ai][bi]);
            }
        }
    }

};

template<typename BitWiseConfig, unsigned Rows>
struct BestRowRegisterBlocking;

template<typename BitWiseConfig>
struct BestRowRegisterBlocking<BitWiseConfig, 1> : public RegisterBlocking<BitWiseConfig, 1, 15> {};
template<typename BitWiseConfig>
struct BestRowRegisterBlocking<BitWiseConfig, 2> : public RegisterBlocking<BitWiseConfig, 2, 7> {};
template<typename BitWiseConfig>
struct BestRowRegisterBlocking<BitWiseConfig, 3> : public RegisterBlocking<BitWiseConfig, 3, 4> {};
// maximize = (R * C) / (R + C) for R + R * C < 16 => any fixed r -> largest C with < 16
// C = floor ((16 - R) / R)

template<
        // template parameter as struct: otherwise some warning about losing alignment information warning
        typename BlockWiseConfig = __m256_block_wise_config,
        unsigned InitialNumRows = 3, unsigned InitialNumColumnVectors = 4
>
struct block_wise {

    typedef ExtendedBlockWiseConfig<BlockWiseConfig> bwc;

    static constexpr unsigned NumRows = InitialNumRows;
    static constexpr unsigned NumColumns = InitialNumColumnVectors * bwc::VectorWidth;

    static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
        bwc::StoreVector(memory, bwc::LoadVector(memory) + vector); };

    template<typename M1, typename M2, typename M3>
    static void multiply(M1 &C, const M2 &A, const M3 &B) {
        assert(C.size1() == A.size1() && C.size2() == B.size2());
        int m = A.size1();
        int k = A.size2();
        int n = B.size2();
        int m_i = 0;
        for(; m_i + InitialNumRows <= m; m_i += InitialNumRows) { // row
            int n_i = 0;
            for(; n_i + InitialNumColumnVectors * bwc::VectorWidth <= n; n_i += InitialNumColumnVectors * bwc::VectorWidth) {
                RegisterBlocking<BlockWiseConfig, InitialNumRows, InitialNumColumnVectors>::handle_block(k, C, A, m_i, B, n_i);
            }
            // calculate remaining columns (like naive_reordered)
            if(n_i < n) {
                for (auto m_i_o = 0; m_i_o < InitialNumRows; ++m_i_o) {
                    for (int p = 0; p < k; ++p) {
                        for (auto n_i_rest = n_i; n_i_rest < n; ++n_i_rest) {
                            C(m_i + m_i_o, n_i_rest) += A(m_i + m_i_o, p) * B(p, n_i_rest);
                        }
                    }
                }
            }
        }
        // calculate remaining rows (like naive_reordered)
        for (; m_i < m; ++m_i) {
            for (int p = 0; p < k; p++) {
                for (int n_i = 0; n_i < n; ++n_i) {
                    C(m_i, n_i) += A(m_i, p) * B(p, n_i);
                }
            }
        }
    }

    template<unsigned CurrentNumRows, unsigned CurrentNumColumnVectors>
    class iterate_columns {
        /**
         * consume all n_i's possible
         */
        template<typename M1, typename M2, typename M3>
        static void consume(size_t k, size_t m_i, size_t &n_i, size_t n, M1 &C, const M2 &A, const M3 &B) {
            for (; n_i + CurrentNumColumnVectors * bwc::VectorWidth <= n;
                    n_i += CurrentNumColumnVectors * bwc::VectorWidth) {
                RegisterBlocking<BlockWiseConfig, CurrentNumRows, CurrentNumColumnVectors>
                ::handle_block(k, C, A, m_i, B, n_i);
            }
        }

    public:

        template<typename M1, typename M2, typename M3>
        static void iterate(size_t k, size_t m_i, size_t &n_i, size_t n, M1 &C, const M2 &A, const M3 &B) {
            consume(k, m_i, n_i, n, C, A, B);
            if(CurrentNumColumnVectors > 1) {
                // try with less column vectors
                iterate_columns<CurrentNumRows, CurrentNumColumnVectors - 1>::iterate(k, m_i, n_i, n, C, A, B);
            } else {
                // do rest of columns manually
                if(n_i < n) {
                    for (auto m_i_o = 0; m_i_o < CurrentNumRows; ++m_i_o) {
                        for (int p = 0; p < k; ++p) {
                            for (auto n_i_rest = n_i; n_i_rest < n; ++n_i_rest) {
                                C(m_i + m_i_o, n_i_rest) += A(m_i + m_i_o, p) * B(p, n_i_rest);
                            }
                        }
                    }
                }
                n_i = n;
            }
            assert(n_i == n);
        }
    };

    template<unsigned CurrentNumRows>
    class iterate_columns<CurrentNumRows, 0> {
    public:
        template<typename M1, typename M2, typename M3>
        static void iterate(size_t k, size_t m_i, size_t &n_i, size_t n, M1 &C, const M2 &A, const M3 &B) {
            throw std::runtime_error("should not be called, this is a bug.");
        }

    };

    template<unsigned CurrentNumRows, unsigned CurrentNumColumnVectors>
    class iterate_rows {

        template<typename M1, typename M2, typename M3>
        static void consume(size_t k, size_t &m_i, size_t m, size_t n, M1 &C, const M2 &A, const M3 &B) {
            for (; m_i + CurrentNumRows <= m; m_i += CurrentNumRows) {
                size_t n_i = 0;
                iterate_columns<CurrentNumRows, CurrentNumColumnVectors>::iterate(k, m_i, n_i, n, C, A, B);
                assert(n_i == n);
            }
        }

    public:

        template<typename M1, typename M2, typename M3>
        static void iterate(size_t k, size_t &m_i, size_t m, size_t n, M1 &C, const M2 &A, const M3 &B) {
            consume(k, m_i, m, n, C, A, B);
            if(CurrentNumRows > 1) {
                // try with less num rows vectors
                iterate_rows<CurrentNumRows - 1, CurrentNumColumnVectors>::iterate(k, m_i, m, n, C, A, B);
            }
            assert(m_i == m);
        }
    };

    template<unsigned CurrentNumColumnVectors>
    class iterate_rows<0, CurrentNumColumnVectors> {

    public:
        template<typename M1, typename M2, typename M3>
        static void iterate(size_t k, size_t &m_i, size_t m, size_t n, M1 &C, const M2 &A, const M3 &B) {
            throw std::runtime_error("should not be called, this is a bug.");
        }
    };

    template<typename M1, typename M2, typename M3>
    static void multiply2(M1 &C, const M2 &A, const M3 &B) {
        assert(C.size1() == A.size1() && C.size2() == B.size2());
        int m = A.size1();
        int k = A.size2();
        int n = B.size2();
        size_t m_i = 0;
        iterate_rows<InitialNumRows, InitialNumColumnVectors>::iterate(k, m_i, m, n, C, A, B);
        assert(m_i == m);
    }

};

template<typename FloatType>
struct block_wise_256;

template<>
struct block_wise_256<float> : public block_wise<__m256_block_wise_config> {
    template<typename M1, typename M2, typename M3>
    void operator()(M1 &C, const M2 &A, const M3 &B) const {
        return multiply(C, A, B);
    }

};

template<>
struct block_wise_256<double> : public block_wise<__m256d_block_wise_config> {
    template<typename M1, typename M2, typename M3>
    void operator()(M1 &C, const M2 &A, const M3 &B) const {
        return multiply(C, A, B);
    }
};

template<typename FloatType>
struct block_wise_256_alternative;

template<>
struct block_wise_256_alternative<float> : public block_wise<__m256_block_wise_config> {
    template<typename M1, typename M2, typename M3>
    void operator()(M1 &C, const M2 &A, const M3 &B) const {
        return multiply2(C, A, B);
    }
};

template<>
struct block_wise_256_alternative<double> : public block_wise<__m256d_block_wise_config> {
    template<typename M1, typename M2, typename M3>
    void operator()(M1 &C, const M2 &A, const M3 &B) const {
        return multiply(C, A, B);
    }
};

template<typename T>
Matrix<T> __attribute__ ((noinline)) block_wise_256_f(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2(), 0);
    block_wise_256<T>::multiply(C, A, B);
    return C;
}

template<typename T>
Matrix<T> __attribute__ ((noinline)) block_wise_256_f2(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2(), 0);
    block_wise_256<T>::multiply2(C, A, B);
    return C;
}

#endif //SMID_MATRIX_REGISTERBLOCKING_H
