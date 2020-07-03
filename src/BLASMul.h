//
// Created by oke on 02.07.20.
//

#ifndef SMID_MATRIX_BLASMUL_H
#define SMID_MATRIX_BLASMUL_H

#include <cblas/cblas.h>
#include "Matrix.h"

template<typename T>
struct blas_functor;

template<>
struct blas_functor<float> {

    static void multiply(Matrix<float> &C, const Matrix<float> &A, const Matrix<float> &B) {
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, C.size1(), C.size2(), A.size2(), 1.,
                    &A(0, 0), A.size2(), &B(0, 0), B.size2(), 1, &C(0, 0), C.size2());
    }

};

template<>
struct blas_functor<double> {

    static void multiply(Matrix<double> &C, const Matrix<double> &A, const Matrix<double> &B) {
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, C.size1(), C.size2(), A.size2(), 1,
                    &A(0, 0), A.size2(), &B(0, 0), B.size2(), 1, &C(0, 0), C.size2());
    }

};

template<typename T>
void blas(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    blas_functor<T>::multiply(C, A, B);
}

#endif //SMID_MATRIX_BLASMUL_H
