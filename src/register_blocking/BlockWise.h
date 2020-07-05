//
// Created by oke on 04.07.20.
//

#ifndef SMID_MATRIX_BLOCKWISE_H
#define SMID_MATRIX_BLOCKWISE_H

#include "detail/BlockWiseImpl.h"

#include <immintrin.h>

struct __m128_block_wise_config {
    using FloatType = float;
    using VectorType = __m128;
    static constexpr auto LoadVector = _mm_loadu_ps;
    static constexpr auto StoreVector = _mm_storeu_ps;
    static constexpr auto BroadcastToVector = _mm_set1_ps;
    static constexpr auto XOR = _mm_xor_ps;
    static constexpr unsigned Registers = 16;
};

struct __m128d_block_wise_config {
    using FloatType = double;
    using VectorType = __m128d;
    static constexpr auto LoadVector = _mm_loadu_pd;
    static constexpr auto StoreVector = _mm_storeu_pd;
    static constexpr auto BroadcastToVector = _mm_set1_pd;
    static constexpr auto XOR = _mm_xor_pd;
    static constexpr unsigned Registers = 16;
};

struct __m256_block_wise_config {
    using FloatType = float;
    using VectorType = __m256;
    static constexpr auto LoadVector = _mm256_loadu_ps;
    static constexpr auto StoreVector = _mm256_storeu_ps;
    static constexpr auto BroadcastToVector = _mm256_set1_ps;
    static constexpr auto XOR = _mm256_xor_ps;
    static constexpr unsigned Registers = 16;
};

struct __m256d_block_wise_config {
    using FloatType = double;
    using VectorType = __m256d;
    static constexpr auto LoadVector = _mm256_loadu_pd;
    static constexpr auto StoreVector = _mm256_storeu_pd;
    static constexpr auto BroadcastToVector = _mm256_set1_pd;
    static constexpr auto XOR = _mm256_xor_pd;
    static constexpr unsigned Registers = 16;
};

#ifdef WITH_AVX512
struct __m512_block_wise_config {
    using FloatType = float;
    using VectorType = __m512;
    static constexpr auto LoadVector = _mm512_loadu_ps;
    static constexpr auto StoreVector = _mm512_storeu_ps;
    static constexpr auto BroadcastToVector = _mm512_set1_ps;
    static constexpr unsigned Registers = 30;
};

struct __m512d_block_wise_config {
    using FloatType = double;
    using VectorType = __m512d;
    static constexpr auto LoadVector = _mm512_loadu_pd;
    static constexpr auto StoreVector = _mm512_storeu_pd;
    static constexpr auto BroadcastToVector = _mm512_set1_pd;
    static constexpr unsigned Registers = 30;
};
#endif

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
