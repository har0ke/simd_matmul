//
// Created by oke on 04.07.20.
//

#ifndef SMID_MATRIX_BLOCKWISE_IMPL_H
#define SMID_MATRIX_BLOCKWISE_IMPL_H

#include "RegisterBlocking.h"

namespace detail {

    template<
            // template parameter as struct: otherwise some warning about losing alignment information warning
            typename BlockWiseConfig
    >
    struct block_wise {

        typedef ExtendedBlockWiseConfig<BlockWiseConfig> bwc;

        static constexpr unsigned InitialNumRows = GetInitialRows(bwc::Registers);
        static constexpr unsigned InitialNumColumnVectors = GetInitialColumnVectors(InitialNumRows, bwc::Registers);
        static constexpr unsigned NumRows = InitialNumRows;
        static constexpr unsigned NumColumns = InitialNumColumnVectors * bwc::VectorWidth;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        /*
        template<typename M1, typename M2, typename M3>
        static void multiply(M1 &C, const M2 &A, const M3 &B) {
            assert(C.size1() == A.size1() && C.size2() == B.size2());
            int m = A.size1();
            int k = A.size2();
            int n = B.size2();
            int m_i = 0;
            for (; m_i + InitialNumRows <= m; m_i += InitialNumRows) { // row
                int n_i = 0;
                for (; n_i + InitialNumColumnVectors * bwc::VectorWidth <= n; n_i += InitialNumColumnVectors *
                                                                                     bwc::VectorWidth) {
                    RegisterBlocking<BlockWiseConfig, InitialNumRows, InitialNumColumnVectors>::handle_block(k, C, A,
                                                                                                             m_i, B,
                                                                                                             n_i);
                }
                // calculate remaining columns (like naive_reordered)
                if (n_i < n) {
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
         */

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
                if (CurrentNumColumnVectors > 1) {
                    // try with less column vectors
                    iterate_columns<CurrentNumRows, CurrentNumColumnVectors - 1>::iterate(k, m_i, n_i, n, C, A, B);
                } else {
                    // do rest of columns manually
                    if (n_i < n) {
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
                if (CurrentNumRows > 1) {
                    // try with less num rows vectors
                    iterate_rows<CurrentNumRows - 1, GetInitialColumnVectors(CurrentNumRows - 1, bwc::Registers)>::iterate(k, m_i, m, n, C, A, B);
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

    template<typename BlockWiseConfig>
    struct block_wise_base : block_wise<BlockWiseConfig> {

        template<typename M1, typename M2, typename M3>
        void operator()(M1 &C, const M2 &A, const M3 &B) const {
            return block_wise<BlockWiseConfig>::multiply2(C, A, B);
        }

    };
}
#endif // SMID_MATRIX_BLOCKWISE_IMPL_H
