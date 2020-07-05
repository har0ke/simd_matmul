//
// Created by oke on 01.07.20.
//

#ifndef SMID_MATRIX_REGISTERBLOCKINGMANUAL_H
#define SMID_MATRIX_REGISTERBLOCKINGMANUAL_H

#include "../../Matrix.h"
#include "ExtendedBlockWiseConfig.h"

template<typename BitWiseConfig, size_t Rows, size_t ColumnVectors>
struct a {
    typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;


    template<typename M1, typename M2, typename M3>
    void do_stuff(int p, int bi, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {

        typename bwc::VectorType bb = bwc::LoadVector(&B(p, bColOffset + bi * bwc::VectorWidth));

        for (int ai = 0; ai < Rows; ai++) { // row index in A (handling regsA rows)
            typename bwc::VectorType aa = bwc::BroadcastToVector(A(aRowOffset + ai, p));
            CReg[ai][bi] += aa * bb;
        }

    }

};


namespace detail {

    template<
            // template parameter as struct: otherwise some warning about losing alignment information warning
            typename BitWiseConfig,
            unsigned _NumRows, unsigned _NumColumnVectors
    >
    struct RegisterBlockingManual {
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = _NumRows;
        static constexpr auto NumColumns = _NumColumnVectors * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {

            // AVX2 has 16 registers
            // should be compiled as registers (total: regA * regB)
            typename bwc::VectorType CReg[_NumRows][_NumColumnVectors] = {{0.0}};
            // iterate over dot-product terms
            for (int p = 0; p < k; p++) { // row index in B and column index in A (handling all rows/columns)
                // Perform the DOT product
                for (int bi = 0; bi < _NumColumnVectors; bi++) { // column index in B (handling regsB * 'VectorWidth' columns)
                    typename bwc::VectorType bb = bwc::LoadVector(&B(p, bColOffset + bi * bwc::VectorWidth));
                    for (int ai = 0; ai < _NumRows; ai++) { // row index in A (handling regsA rows)
                        typename bwc::VectorType aa = bwc::BroadcastToVector(A(aRowOffset + ai, p));
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

}

#endif //SMID_MATRIX_REGISTERBLOCKINGMANUAL_H
