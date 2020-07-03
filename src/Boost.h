//
// Created by oke on 01.07.20.
//

#ifndef SMID_MATRIX_BOOST_H
#define SMID_MATRIX_BOOST_H

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>

template<typename T>
Matrix<T> __attribute__ ((noinline)) boost_axpy_mul(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2(), 0);
    boost::numeric::ublas::axpy_prod(A, B, C);
    return C;
}

template<typename T>
Matrix<T> __attribute__ ((noinline)) boost_blocked_mul_64(const Matrix<T> &A, const Matrix<T> &B) {
    return boost::numeric::ublas::block_prod<Matrix<T>, 64>(A, B);
}

template<typename T>
Matrix<T> __attribute__ ((noinline)) boost_blocked_mul_256(const Matrix<T> &A, const Matrix<T> &B) {
    return boost::numeric::ublas::block_prod<Matrix<T>, 256>(A, B);
}
template<typename T>
Matrix<T> __attribute__ ((noinline)) boost_mul(const Matrix<T> &A, const Matrix<T> &B) {
    return boost::numeric::ublas::prod(A, B);
}
#endif //SMID_MATRIX_BOOST_H
