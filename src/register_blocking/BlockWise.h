//
// Created by oke on 04.07.20.
//

#ifndef SMID_MATRIX_BLOCKWISE_H
#define SMID_MATRIX_BLOCKWISE_H

#include "detail/BlockWiseImpl.h"
#include "detail/BlockWiseConfigs.h"

enum AvxVersion {
    SSE,
    AVX2,
#ifdef WITH_AVX512
    AVX512
#endif
};

template<typename FloatType, AvxVersion avxVersion>
struct block_wise;

template<> struct block_wise<float, SSE> : public detail::block_wise_base<__m128_block_wise_config> {};
template<> struct block_wise<double, SSE> : public detail::block_wise_base<__m128d_block_wise_config> {};

template<> struct block_wise<float, AVX2> : public detail::block_wise_base<__m256_block_wise_config> {};
template<> struct block_wise<double, AVX2> : public detail::block_wise_base<__m256d_block_wise_config> {};

#ifdef WITH_AVX512
template<> struct block_wise<float, AVX512> : public detail::block_wise_base<__m512_block_wise_config> {};
    template<> struct block_wise<double, AVX512> : public detail::block_wise_base<__m512d_block_wise_config> {};
#endif

template<typename T>
void __attribute__ ((noinline)) block_wise_sse(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    block_wise<T, SSE>::multiply2(C, A, B);
}

template<typename T>
void __attribute__ ((noinline)) block_wise_avx2(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    block_wise<T, AVX2>::multiply2(C, A, B);
}

#ifdef WITH_AVX512
template<typename T>
void __attribute__ ((noinline)) block_wise_avx512(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B) {
    block_wise<T, AVX512>::multiply2(C, A, B);
}
#endif

#endif //SMID_MATRIX_BLOCKWISE_H
