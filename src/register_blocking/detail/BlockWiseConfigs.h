//
// Created by oke on 05.07.20.
//

#ifndef SMID_MATRIX_BLOCKWISECONFIGS_H
#define SMID_MATRIX_BLOCKWISECONFIGS_H

#include <immintrin.h>

template<typename Config, unsigned CurrentNumRows>
struct masked_remaining_columns {

    static constexpr bool IsCustom = true;

    typedef ExtendedBlockWiseConfig<Config> bwc;

    template<typename M1, typename M2, typename M3>
    static void handle(size_t k, size_t m_i, size_t &n_i, size_t n, M1 &C, const M2 &A, const M3 &B) {
        typename Config::Mask mask = 0;
        mask = (~mask);
        mask = mask << (n - n_i);
        mask = ~mask;
        typename bwc::VectorType CReg[CurrentNumRows] = { 0.0 };
        for (int p = 0; p < k; p++) {
            typename bwc::VectorType bb = Config::LoadVectorMasked({ 0.0 }, mask, &B(p, n_i));
            for (int ai = 0; ai < CurrentNumRows; ai++) { // row index in A (handling regsA rows)
                typename bwc::VectorType aa = bwc::BroadcastToVector(A(m_i + ai, p));
                CReg[ai] += aa * bb;
            }
        }
        for (int ai = 0; ai < CurrentNumRows; ai++) {
            auto memory = &C(m_i + ai, n_i);
            Config::StoreVectorMasked(memory, mask, Config::LoadVectorMasked({ 0.0 }, mask, memory) + CReg[ai]);
        }
    }

};

struct __m128_block_wise_config {
    static constexpr bool has_sub_config = false;
    using FloatType = float;
    using VectorType = __m128;
    static constexpr auto LoadVector = _mm_loadu_ps;
    static constexpr auto StoreVector = _mm_storeu_ps;
    static constexpr auto BroadcastToVector = _mm_set1_ps;
    static constexpr auto XOR = _mm_xor_ps;
    static constexpr unsigned Registers = 16;
};

struct __m128d_block_wise_config {
    static constexpr bool has_sub_config = false;
    using FloatType = double;
    using VectorType = __m128d;
    static constexpr auto LoadVector = _mm_loadu_pd;
    static constexpr auto StoreVector = _mm_storeu_pd;
    static constexpr auto BroadcastToVector = _mm_set1_pd;
    static constexpr auto XOR = _mm_xor_pd;
    static constexpr unsigned Registers = 16;
};

struct __m256_block_wise_config {
    static constexpr bool has_sub_config = true;
    using SubConfig = __m128_block_wise_config;

    using FloatType = float;
    using VectorType = __m256;
    static constexpr auto LoadVector = _mm256_loadu_ps;
    static constexpr auto StoreVector = _mm256_storeu_ps;
    static constexpr auto BroadcastToVector = _mm256_set1_ps;
    static constexpr auto XOR = _mm256_xor_ps;
    static constexpr unsigned Registers = 16;
};

struct __m256d_block_wise_config {
    static constexpr bool has_sub_config = true;
    using SubConfig = __m128d_block_wise_config;
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
    static constexpr bool has_sub_config = true;
    using SubConfig = __m256_block_wise_config;
    using FloatType = float;
    using VectorType = __m512;
    using Mask = __mmask16;
    static constexpr auto LoadVectorMasked = _mm512_mask_loadu_ps;
    static constexpr auto StoreVectorMasked = _mm512_mask_storeu_ps;
    static constexpr auto LoadVector = _mm512_loadu_ps;
    static constexpr auto StoreVector = _mm512_storeu_ps;
    static constexpr auto BroadcastToVector = _mm512_set1_ps;
    static constexpr auto XOR = _mm512_xor_ps;
    static constexpr unsigned Registers = 32;
};

struct __m512d_block_wise_config {
    static constexpr bool has_sub_config = true;
    using SubConfig = __m256d_block_wise_config;
    using FloatType = double;
    using VectorType = __m512d;
    using Mask = __mmask16;
    static constexpr auto LoadVectorMasked = _mm512_mask_loadu_pd;
    static constexpr auto StoreVectorMasked = _mm512_mask_storeu_pd;
    static constexpr auto LoadVector = _mm512_loadu_pd;
    static constexpr auto StoreVector = _mm512_storeu_pd;
    static constexpr auto BroadcastToVector = _mm512_set1_pd;
    static constexpr auto XOR = _mm512_xor_pd;
    static constexpr unsigned Registers = 32;
};

template<typename BlockWiseConfig, unsigned CurrentNumRows>
struct remaining_columns;

template<unsigned CurrentNumRows>
struct remaining_columns<__m512_block_wise_config, CurrentNumRows>
        : masked_remaining_columns<__m512_block_wise_config, CurrentNumRows> {};

template<unsigned CurrentNumRows>
struct remaining_columns<__m512d_block_wise_config, CurrentNumRows>
        : masked_remaining_columns<__m512d_block_wise_config, CurrentNumRows> {};

#endif


#endif //SMID_MATRIX_BLOCKWISECONFIGS_H
