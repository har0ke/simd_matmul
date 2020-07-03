//
// Created by oke on 01.07.20.
//

#ifndef SMID_MATRIX_NAIVE_H
#define SMID_MATRIX_NAIVE_H

template<typename T>
Matrix<T> __attribute__ ((noinline)) naive(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2(), 0);
    assert(A.size2() == B.size1());

    for (int i = 0; i < A.size1(); i++) {
        for (int j = 0; j < B.size2(); j++) {
            for (int p = 0; p < B.size1(); p++) {
                C(i, j) += A(i, p) * B(p, j);
            }
        }
    }
    return C;
}

template<typename M1, typename M2, typename M3>
void __attribute__ ((noinline)) _naive_reordered(M1 &C, const M2 &A, const M3 &B) {
    assert(A.size2() == B.size1());
    for (int i = 0; i < A.size1(); i++) {
        for (int p = 0; p < B.size1(); p++) {
            for (int j = 0; j < B.size2(); j++) {
                C(i, j) += A(i, p) * B(p, j);
            }
        }
    }
}
template<typename T>
Matrix<T> naive_reordered(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2(), 0);
    _naive_reordered(C, A, B);
    return C;
}

#endif //SMID_MATRIX_NAIVE_H
