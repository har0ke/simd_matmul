//
// Created by oke on 01.07.20.
//

#ifndef SMID_MATRIX_REGISTERBLOCKING_H
#define SMID_MATRIX_REGISTERBLOCKING_H

#include "../../Matrix.h"
#include "ExtendedBlockWiseConfig.h"

namespace detail {

    template<
            // template parameter as struct: otherwise some warning about losing alignment information warning
            typename BitWiseConfig,
            unsigned _NumRows, unsigned _NumColumnVectors
    >
    struct RegisterBlocking {
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
                for (int bi = 0;
                     bi < _NumColumnVectors; bi++) { // column index in B (handling regsB * 'VectorWidth' columns)
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

/*
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 4> {
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {

            // AVX2 has 16 registers
            // should be compiled as registers (total: regA * regB)
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r3c3;
            typename bwc::VectorType r3c4;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType c;

            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r3c3 = bwc::XOR(r3c3, r3c3);
            r3c4 = bwc::XOR(r3c4, r3c4);

            // iterate over dot-product terms
            for (int p = 0; p < k; p++) { // row index in B and column index in A (handling all rows/columns)
                // Perform the DOT product
                r1 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 2, p));

                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;

                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;

                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                r3c3 += r3 * c;

                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                r3c4 += r3 * c;
            }

            // total regA * regB + regB registers

            // Accumulate the results into C.
            AddAndStore(&C(aRowOffset + 0, bColOffset + 0 * bwc::VectorWidth), r1c1);
            AddAndStore(&C(aRowOffset + 1, bColOffset + 0 * bwc::VectorWidth), r2c1);
            AddAndStore(&C(aRowOffset + 2, bColOffset + 0 * bwc::VectorWidth), r3c1);
            AddAndStore(&C(aRowOffset + 0, bColOffset + 1 * bwc::VectorWidth), r1c2);
            AddAndStore(&C(aRowOffset + 1, bColOffset + 1 * bwc::VectorWidth), r2c2);
            AddAndStore(&C(aRowOffset + 2, bColOffset + 1 * bwc::VectorWidth), r3c2);
            AddAndStore(&C(aRowOffset + 0, bColOffset + 2 * bwc::VectorWidth), r1c3);
            AddAndStore(&C(aRowOffset + 1, bColOffset + 2 * bwc::VectorWidth), r2c3);
            AddAndStore(&C(aRowOffset + 2, bColOffset + 2 * bwc::VectorWidth), r3c3);
            AddAndStore(&C(aRowOffset + 0, bColOffset + 3 * bwc::VectorWidth), r1c4);
            AddAndStore(&C(aRowOffset + 1, bColOffset + 3 * bwc::VectorWidth), r2c4);
            AddAndStore(&C(aRowOffset + 2, bColOffset + 3 * bwc::VectorWidth), r3c4);
        }
    };
*/

}

#endif //SMID_MATRIX_REGISTERBLOCKING_H
