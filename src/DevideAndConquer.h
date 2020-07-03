//
// Created by oke on 01.07.20.
//

#ifndef SMID_MATRIX_DEVIDEANDCONQUER_H
#define SMID_MATRIX_DEVIDEANDCONQUER_H
#include "Boost.h"
#include "Naive.h"

enum SplitAction {
    SplitA, SplitB, SplitBoth, DoNotSplit
};

size_t splitByMultiple(size_t value, size_t multiple) {
    auto result = (value / (multiple * 2)) * multiple;
    return result == 0 ? 1 : result;
}

template<typename Multiplier, typename M1, typename M2, typename M3>
void _divide_and_conquer(M1 &C, const M2 &A, const M3 &B) {
    assert(C.size1() == A.size1() && C.size2() == B.size2());
    assert(A.size2() == B.size1());
    size_t n = A.size1();
    size_t p = A.size2();
    size_t m = B.size2();

    switch (Multiplier::action(n, p, m)) {
        case DoNotSplit:
            constexpr Multiplier multiplier;
            multiplier(C, A, B);
            break;
        case SplitA:
            {
                size_t split_index = splitByMultiple(n, Multiplier::SplitMultipleM);
                if (split_index == 0) split_index = 1;
                const auto A1 = boost::numeric::ublas::project(A, {0, split_index}, {0, A.size2()});
                const auto A2 = boost::numeric::ublas::project(A, {split_index, A.size1()}, {0, A.size2()});
                auto C1 = boost::numeric::ublas::project(C, {0, split_index}, {0, C.size2()});
                auto C2 = boost::numeric::ublas::project(C, {split_index, C.size1()}, {0, C.size2()});
                _divide_and_conquer<Multiplier>(C1, A1, B);
                _divide_and_conquer<Multiplier>(C2, A2, B);
            }
            break;
        case SplitB:
            {
                size_t split_index = splitByMultiple(m, Multiplier::SplitMultipleN);
                if (split_index == 0) split_index = 1;
                auto B1 = boost::numeric::ublas::project(B, {0, B.size1()}, {0, split_index});
                auto B2 = boost::numeric::ublas::project(B, {0, B.size1()}, {split_index, B.size2()});
                auto C1 = boost::numeric::ublas::project(C, {0, C.size1()}, {0, split_index});
                auto C2 = boost::numeric::ublas::project(C, {0, C.size1()}, {split_index, C.size2()});
                _divide_and_conquer<Multiplier>(C1, A, B1);
                _divide_and_conquer<Multiplier>(C2, A, B2);
            }
            break;
        case SplitBoth:
            {
                size_t split_index = splitByMultiple(p, Multiplier::SplitMultipleP);
                auto B1 = boost::numeric::ublas::project(B, {0, split_index}, {0, B.size2()});
                auto B2 = boost::numeric::ublas::project(B, {split_index, B.size1()}, {0, B.size2()});
                auto A1 = boost::numeric::ublas::project(A, {0, A.size1()}, {0, split_index});
                auto A2 = boost::numeric::ublas::project(A, {0, A.size1()}, {split_index, A.size2()});
                _divide_and_conquer<Multiplier>(C, A1, B1);
                _divide_and_conquer<Multiplier>(C, A2, B2);
            }
            break;
        default:
            std::cerr << "Invalid split action" << std::endl;
    }
}

template<unsigned NumRows, unsigned NumColumns>
struct multiplier_naive_functor {

    static constexpr unsigned SplitMultipleN = NumRows;
    static constexpr unsigned SplitMultipleP = 1;
    static constexpr unsigned SplitMultipleM = NumColumns;

    static SplitAction action(unsigned m, unsigned p, unsigned n) {
        size_t max_dim = std::max(std::max(m, n), p);
        if (m <= NumRows && n <= NumColumns) {
            return DoNotSplit;
        } else if (max_dim == m) {
            return SplitA;
        } else if (max_dim == n) {
            return SplitB;
        } else {
            return SplitBoth;
        }
    }


    template<typename M1, typename M2, typename M3>
    void operator()(M1 &C, const M2 &A, const M3 &B) const {
        if(C.size1() == NumRows && C.size2() == NumColumns) {
            for (int i = 0; i < NumRows; i++) {
                for (int p = 0; p < B.size1(); p++) {
                    for (int j = 0; j < NumColumns; j++) {
                        C(i, j) += A(i, p) * B(p, j);
                    }
                }
            }
            return;
        }
        naive_reordered(C, A, B);
    }
};


template<typename FloatType, AvxVersion version>
struct multiplier_block_wise : block_wise<FloatType, version> {

    typedef block_wise<FloatType, version> Base;

    static constexpr unsigned SplitMultipleM = 5 * Base::NumRows;
    static constexpr unsigned SplitMultipleP = 20;
    static constexpr unsigned SplitMultipleN = Base::NumColumns;

    static SplitAction action(unsigned m, unsigned p, unsigned n) {
        size_t m_p = m / SplitMultipleM;
        size_t p_p = p / SplitMultipleP;
        size_t n_p = n / SplitMultipleN;
        unsigned _SplitMultipleM = SplitMultipleM;
        unsigned _SplitMultipleP = 1;
        unsigned _SplitMultipleN = SplitMultipleN;

        auto max_dim = std::max(m_p, std::max(p_p, n_p));
        if (m <= SplitMultipleM && n <= SplitMultipleN) {
            return DoNotSplit;
        } else if (max_dim == m_p) {
            return SplitA;
        } else if (max_dim == n_p) {
            return SplitB;
        } else if (p > SplitMultipleP){
            return SplitBoth;
        } else {
            return DoNotSplit;
        }
    }

};


template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_naive_r1(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_naive_functor<5, 5>>(C, A, B);
}

template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_naive_r2(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_naive_functor<50, 50>>(C, A, B);
}

template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_naive_r3(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_naive_functor<200, 200>>(C, A, B);
}

template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_naive_r4(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_naive_functor<500, 500>>(C, A, B);
}

template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_naive_r5(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_naive_functor<1000, 1000>>(C, A, B);
}

template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_block_avx2(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_block_wise<T, AVX2>>(C, A, B);
}


#ifdef WITH_AVX512
template<typename T>
void __attribute__ ((noinline)) divide_and_conquer_block_avx512(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    _divide_and_conquer<multiplier_block_wise<T, AVX512>>(C, A, B);
}
#endif

#endif //SMID_MATRIX_DEVIDEANDCONQUER_H
