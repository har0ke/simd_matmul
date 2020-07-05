

namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 1> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            r0c0 = bwc::XOR(r0c0, r0c0);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 2> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 3> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 4> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 5> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 6> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 7> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 8> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 9> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 10> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 11> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 12> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 13> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 14> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 15> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 16> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 17> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 18> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 19> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 20> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 21> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 22> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 23> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 24> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 25> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            typename bwc::VectorType r0c24;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);
            r0c24 = bwc::XOR(r0c24, r0c24);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 24 * bwc::VectorWidth));
                r0c24 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c24);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 26> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            typename bwc::VectorType r0c24;
            typename bwc::VectorType r0c25;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);
            r0c24 = bwc::XOR(r0c24, r0c24);
            r0c25 = bwc::XOR(r0c25, r0c25);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 24 * bwc::VectorWidth));
                r0c24 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 25 * bwc::VectorWidth));
                r0c25 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c24);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c25);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 27> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            typename bwc::VectorType r0c24;
            typename bwc::VectorType r0c25;
            typename bwc::VectorType r0c26;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);
            r0c24 = bwc::XOR(r0c24, r0c24);
            r0c25 = bwc::XOR(r0c25, r0c25);
            r0c26 = bwc::XOR(r0c26, r0c26);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 24 * bwc::VectorWidth));
                r0c24 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 25 * bwc::VectorWidth));
                r0c25 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 26 * bwc::VectorWidth));
                r0c26 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c24);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c25);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c26);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 28> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            typename bwc::VectorType r0c24;
            typename bwc::VectorType r0c25;
            typename bwc::VectorType r0c26;
            typename bwc::VectorType r0c27;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);
            r0c24 = bwc::XOR(r0c24, r0c24);
            r0c25 = bwc::XOR(r0c25, r0c25);
            r0c26 = bwc::XOR(r0c26, r0c26);
            r0c27 = bwc::XOR(r0c27, r0c27);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 24 * bwc::VectorWidth));
                r0c24 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 25 * bwc::VectorWidth));
                r0c25 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 26 * bwc::VectorWidth));
                r0c26 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 27 * bwc::VectorWidth));
                r0c27 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c24);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c25);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c26);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c27);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 29> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            typename bwc::VectorType r0c24;
            typename bwc::VectorType r0c25;
            typename bwc::VectorType r0c26;
            typename bwc::VectorType r0c27;
            typename bwc::VectorType r0c28;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);
            r0c24 = bwc::XOR(r0c24, r0c24);
            r0c25 = bwc::XOR(r0c25, r0c25);
            r0c26 = bwc::XOR(r0c26, r0c26);
            r0c27 = bwc::XOR(r0c27, r0c27);
            r0c28 = bwc::XOR(r0c28, r0c28);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 24 * bwc::VectorWidth));
                r0c24 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 25 * bwc::VectorWidth));
                r0c25 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 26 * bwc::VectorWidth));
                r0c26 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 27 * bwc::VectorWidth));
                r0c27 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 28 * bwc::VectorWidth));
                r0c28 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c24);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c25);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c26);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c27);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c28);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 1, 30> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r0c14;
            typename bwc::VectorType r0c15;
            typename bwc::VectorType r0c16;
            typename bwc::VectorType r0c17;
            typename bwc::VectorType r0c18;
            typename bwc::VectorType r0c19;
            typename bwc::VectorType r0c20;
            typename bwc::VectorType r0c21;
            typename bwc::VectorType r0c22;
            typename bwc::VectorType r0c23;
            typename bwc::VectorType r0c24;
            typename bwc::VectorType r0c25;
            typename bwc::VectorType r0c26;
            typename bwc::VectorType r0c27;
            typename bwc::VectorType r0c28;
            typename bwc::VectorType r0c29;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r0c14 = bwc::XOR(r0c14, r0c14);
            r0c15 = bwc::XOR(r0c15, r0c15);
            r0c16 = bwc::XOR(r0c16, r0c16);
            r0c17 = bwc::XOR(r0c17, r0c17);
            r0c18 = bwc::XOR(r0c18, r0c18);
            r0c19 = bwc::XOR(r0c19, r0c19);
            r0c20 = bwc::XOR(r0c20, r0c20);
            r0c21 = bwc::XOR(r0c21, r0c21);
            r0c22 = bwc::XOR(r0c22, r0c22);
            r0c23 = bwc::XOR(r0c23, r0c23);
            r0c24 = bwc::XOR(r0c24, r0c24);
            r0c25 = bwc::XOR(r0c25, r0c25);
            r0c26 = bwc::XOR(r0c26, r0c26);
            r0c27 = bwc::XOR(r0c27, r0c27);
            r0c28 = bwc::XOR(r0c28, r0c28);
            r0c29 = bwc::XOR(r0c29, r0c29);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 14 * bwc::VectorWidth));
                r0c14 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 15 * bwc::VectorWidth));
                r0c15 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 16 * bwc::VectorWidth));
                r0c16 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 17 * bwc::VectorWidth));
                r0c17 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 18 * bwc::VectorWidth));
                r0c18 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 19 * bwc::VectorWidth));
                r0c19 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 20 * bwc::VectorWidth));
                r0c20 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 21 * bwc::VectorWidth));
                r0c21 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 22 * bwc::VectorWidth));
                r0c22 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 23 * bwc::VectorWidth));
                r0c23 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 24 * bwc::VectorWidth));
                r0c24 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 25 * bwc::VectorWidth));
                r0c25 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 26 * bwc::VectorWidth));
                r0c26 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 27 * bwc::VectorWidth));
                r0c27 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 28 * bwc::VectorWidth));
                r0c28 += r0 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 29 * bwc::VectorWidth));
                r0c29 += r0 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c14);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c15);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c16);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c17);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c18);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c19);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c20);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c21);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c22);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c23);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c24);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c25);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c26);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c27);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c28);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c29);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 1> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r1c0;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r1c0 = bwc::XOR(r1c0, r1c0);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 2> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 3> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 4> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 5> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 6> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 7> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 8> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 9> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 10> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            typename bwc::VectorType r1c9;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);
            r1c9 = bwc::XOR(r1c9, r1c9);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                r1c9 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c9);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 11> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            typename bwc::VectorType r1c9;
            typename bwc::VectorType r1c10;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);
            r1c9 = bwc::XOR(r1c9, r1c9);
            r1c10 = bwc::XOR(r1c10, r1c10);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                r1c9 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                r1c10 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c10);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 12> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            typename bwc::VectorType r1c9;
            typename bwc::VectorType r1c10;
            typename bwc::VectorType r1c11;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);
            r1c9 = bwc::XOR(r1c9, r1c9);
            r1c10 = bwc::XOR(r1c10, r1c10);
            r1c11 = bwc::XOR(r1c11, r1c11);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                r1c9 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                r1c10 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                r1c11 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c11);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 13> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            typename bwc::VectorType r1c9;
            typename bwc::VectorType r1c10;
            typename bwc::VectorType r1c11;
            typename bwc::VectorType r1c12;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);
            r1c9 = bwc::XOR(r1c9, r1c9);
            r1c10 = bwc::XOR(r1c10, r1c10);
            r1c11 = bwc::XOR(r1c11, r1c11);
            r1c12 = bwc::XOR(r1c12, r1c12);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                r1c9 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                r1c10 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                r1c11 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                r1c12 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c12);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 2, 14> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r0c9;
            typename bwc::VectorType r0c10;
            typename bwc::VectorType r0c11;
            typename bwc::VectorType r0c12;
            typename bwc::VectorType r0c13;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            typename bwc::VectorType r1c9;
            typename bwc::VectorType r1c10;
            typename bwc::VectorType r1c11;
            typename bwc::VectorType r1c12;
            typename bwc::VectorType r1c13;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r0c9 = bwc::XOR(r0c9, r0c9);
            r0c10 = bwc::XOR(r0c10, r0c10);
            r0c11 = bwc::XOR(r0c11, r0c11);
            r0c12 = bwc::XOR(r0c12, r0c12);
            r0c13 = bwc::XOR(r0c13, r0c13);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);
            r1c9 = bwc::XOR(r1c9, r1c9);
            r1c10 = bwc::XOR(r1c10, r1c10);
            r1c11 = bwc::XOR(r1c11, r1c11);
            r1c12 = bwc::XOR(r1c12, r1c12);
            r1c13 = bwc::XOR(r1c13, r1c13);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 9 * bwc::VectorWidth));
                r0c9 += r0 * c;
                r1c9 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 10 * bwc::VectorWidth));
                r0c10 += r0 * c;
                r1c10 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 11 * bwc::VectorWidth));
                r0c11 += r0 * c;
                r1c11 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 12 * bwc::VectorWidth));
                r0c12 += r0 * c;
                r1c12 += r1 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 13 * bwc::VectorWidth));
                r0c13 += r0 * c;
                r1c13 += r1 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c13);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c9);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c10);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c11);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c12);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c13);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 1> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r2c0;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r2c0 = bwc::XOR(r2c0, r2c0);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 2> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 3> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
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
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 5> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 6> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r2c5;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r2c5 = bwc::XOR(r2c5, r2c5);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                r2c5 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c5);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 7> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r2c5;
            typename bwc::VectorType r2c6;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r2c5 = bwc::XOR(r2c5, r2c5);
            r2c6 = bwc::XOR(r2c6, r2c6);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                r2c5 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                r2c6 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c6);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 8> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r2c5;
            typename bwc::VectorType r2c6;
            typename bwc::VectorType r2c7;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r2c5 = bwc::XOR(r2c5, r2c5);
            r2c6 = bwc::XOR(r2c6, r2c6);
            r2c7 = bwc::XOR(r2c7, r2c7);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                r2c5 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                r2c6 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                r2c7 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c7);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 3, 9> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r0c6;
            typename bwc::VectorType r0c7;
            typename bwc::VectorType r0c8;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r1c6;
            typename bwc::VectorType r1c7;
            typename bwc::VectorType r1c8;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r2c5;
            typename bwc::VectorType r2c6;
            typename bwc::VectorType r2c7;
            typename bwc::VectorType r2c8;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r0c6 = bwc::XOR(r0c6, r0c6);
            r0c7 = bwc::XOR(r0c7, r0c7);
            r0c8 = bwc::XOR(r0c8, r0c8);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r1c6 = bwc::XOR(r1c6, r1c6);
            r1c7 = bwc::XOR(r1c7, r1c7);
            r1c8 = bwc::XOR(r1c8, r1c8);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r2c5 = bwc::XOR(r2c5, r2c5);
            r2c6 = bwc::XOR(r2c6, r2c6);
            r2c7 = bwc::XOR(r2c7, r2c7);
            r2c8 = bwc::XOR(r2c8, r2c8);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                r2c5 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 6 * bwc::VectorWidth));
                r0c6 += r0 * c;
                r1c6 += r1 * c;
                r2c6 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 7 * bwc::VectorWidth));
                r0c7 += r0 * c;
                r1c7 += r1 * c;
                r2c7 += r2 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 8 * bwc::VectorWidth));
                r0c8 += r0 * c;
                r1c8 += r1 * c;
                r2c8 += r2 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c8);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c8);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c5);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c6);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c7);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c8);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 4, 1> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r3c0;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r3c0 = bwc::XOR(r3c0, r3c0);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 4, 2> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 4, 3> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 4, 4> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r3c3;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r3c3 = bwc::XOR(r3c3, r3c3);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                r3c3 += r3 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c3);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 4, 5> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r3c3;
            typename bwc::VectorType r3c4;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r3c3 = bwc::XOR(r3c3, r3c3);
            r3c4 = bwc::XOR(r3c4, r3c4);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                r3c3 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                r3c4 += r3 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c4);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 4, 6> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r0c5;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r1c5;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r2c5;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r3c3;
            typename bwc::VectorType r3c4;
            typename bwc::VectorType r3c5;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r0c5 = bwc::XOR(r0c5, r0c5);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r1c5 = bwc::XOR(r1c5, r1c5);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r2c5 = bwc::XOR(r2c5, r2c5);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r3c3 = bwc::XOR(r3c3, r3c3);
            r3c4 = bwc::XOR(r3c4, r3c4);
            r3c5 = bwc::XOR(r3c5, r3c5);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                r3c3 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                r3c4 += r3 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 5 * bwc::VectorWidth));
                r0c5 += r0 * c;
                r1c5 += r1 * c;
                r2c5 += r2 * c;
                r3c5 += r3 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c5);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c5);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c5);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c4);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c5);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 5, 1> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r4;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r4c0;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r4c0 = bwc::XOR(r4c0, r4c0);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                r4 = bwc::BroadcastToVector(A(aRowOffset + 4, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                r4c0 += r4 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r4c0);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 5, 2> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r4;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r4c0;
            typename bwc::VectorType r4c1;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r4c0 = bwc::XOR(r4c0, r4c0);
            r4c1 = bwc::XOR(r4c1, r4c1);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                r4 = bwc::BroadcastToVector(A(aRowOffset + 4, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                r4c0 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                r4c1 += r4 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r4c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c1);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 5, 3> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r4;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r4c0;
            typename bwc::VectorType r4c1;
            typename bwc::VectorType r4c2;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r4c0 = bwc::XOR(r4c0, r4c0);
            r4c1 = bwc::XOR(r4c1, r4c1);
            r4c2 = bwc::XOR(r4c2, r4c2);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                r4 = bwc::BroadcastToVector(A(aRowOffset + 4, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                r4c0 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                r4c1 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
                r4c2 += r4 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r4c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c2);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 5, 4> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r4;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r3c3;
            typename bwc::VectorType r4c0;
            typename bwc::VectorType r4c1;
            typename bwc::VectorType r4c2;
            typename bwc::VectorType r4c3;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r3c3 = bwc::XOR(r3c3, r3c3);
            r4c0 = bwc::XOR(r4c0, r4c0);
            r4c1 = bwc::XOR(r4c1, r4c1);
            r4c2 = bwc::XOR(r4c2, r4c2);
            r4c3 = bwc::XOR(r4c3, r4c3);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                r4 = bwc::BroadcastToVector(A(aRowOffset + 4, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                r4c0 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                r4c1 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
                r4c2 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                r3c3 += r3 * c;
                r4c3 += r4 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c3);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r4c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c3);
        
        }
    };

}


namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, 5, 5> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
            typename bwc::VectorType c;
            typename bwc::VectorType r0;
            typename bwc::VectorType r1;
            typename bwc::VectorType r2;
            typename bwc::VectorType r3;
            typename bwc::VectorType r4;
            typename bwc::VectorType r0c0;
            typename bwc::VectorType r0c1;
            typename bwc::VectorType r0c2;
            typename bwc::VectorType r0c3;
            typename bwc::VectorType r0c4;
            typename bwc::VectorType r1c0;
            typename bwc::VectorType r1c1;
            typename bwc::VectorType r1c2;
            typename bwc::VectorType r1c3;
            typename bwc::VectorType r1c4;
            typename bwc::VectorType r2c0;
            typename bwc::VectorType r2c1;
            typename bwc::VectorType r2c2;
            typename bwc::VectorType r2c3;
            typename bwc::VectorType r2c4;
            typename bwc::VectorType r3c0;
            typename bwc::VectorType r3c1;
            typename bwc::VectorType r3c2;
            typename bwc::VectorType r3c3;
            typename bwc::VectorType r3c4;
            typename bwc::VectorType r4c0;
            typename bwc::VectorType r4c1;
            typename bwc::VectorType r4c2;
            typename bwc::VectorType r4c3;
            typename bwc::VectorType r4c4;
            r0c0 = bwc::XOR(r0c0, r0c0);
            r0c1 = bwc::XOR(r0c1, r0c1);
            r0c2 = bwc::XOR(r0c2, r0c2);
            r0c3 = bwc::XOR(r0c3, r0c3);
            r0c4 = bwc::XOR(r0c4, r0c4);
            r1c0 = bwc::XOR(r1c0, r1c0);
            r1c1 = bwc::XOR(r1c1, r1c1);
            r1c2 = bwc::XOR(r1c2, r1c2);
            r1c3 = bwc::XOR(r1c3, r1c3);
            r1c4 = bwc::XOR(r1c4, r1c4);
            r2c0 = bwc::XOR(r2c0, r2c0);
            r2c1 = bwc::XOR(r2c1, r2c1);
            r2c2 = bwc::XOR(r2c2, r2c2);
            r2c3 = bwc::XOR(r2c3, r2c3);
            r2c4 = bwc::XOR(r2c4, r2c4);
            r3c0 = bwc::XOR(r3c0, r3c0);
            r3c1 = bwc::XOR(r3c1, r3c1);
            r3c2 = bwc::XOR(r3c2, r3c2);
            r3c3 = bwc::XOR(r3c3, r3c3);
            r3c4 = bwc::XOR(r3c4, r3c4);
            r4c0 = bwc::XOR(r4c0, r4c0);
            r4c1 = bwc::XOR(r4c1, r4c1);
            r4c2 = bwc::XOR(r4c2, r4c2);
            r4c3 = bwc::XOR(r4c3, r4c3);
            r4c4 = bwc::XOR(r4c4, r4c4);

            for (int p = 0; p < k; p++) {
                r0 = bwc::BroadcastToVector(A(aRowOffset + 0, p));
                r1 = bwc::BroadcastToVector(A(aRowOffset + 1, p));
                r2 = bwc::BroadcastToVector(A(aRowOffset + 2, p));
                r3 = bwc::BroadcastToVector(A(aRowOffset + 3, p));
                r4 = bwc::BroadcastToVector(A(aRowOffset + 4, p));
                c = bwc::LoadVector(&B(p, bColOffset + 0 * bwc::VectorWidth));
                r0c0 += r0 * c;
                r1c0 += r1 * c;
                r2c0 += r2 * c;
                r3c0 += r3 * c;
                r4c0 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 1 * bwc::VectorWidth));
                r0c1 += r0 * c;
                r1c1 += r1 * c;
                r2c1 += r2 * c;
                r3c1 += r3 * c;
                r4c1 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 2 * bwc::VectorWidth));
                r0c2 += r0 * c;
                r1c2 += r1 * c;
                r2c2 += r2 * c;
                r3c2 += r3 * c;
                r4c2 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 3 * bwc::VectorWidth));
                r0c3 += r0 * c;
                r1c3 += r1 * c;
                r2c3 += r2 * c;
                r3c3 += r3 * c;
                r4c3 += r4 * c;
                c = bwc::LoadVector(&B(p, bColOffset + 4 * bwc::VectorWidth));
                r0c4 += r0 * c;
                r1c4 += r1 * c;
                r2c4 += r2 * c;
                r3c4 += r3 * c;
                r4c4 += r4 * c;
            }
            
            size_t row = aRowOffset;
            size_t column;
            column = bColOffset;
            AddAndStore(&C(row, column), r0c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r0c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r1c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r1c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r2c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r2c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r3c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r3c4);
            ++row_index;
            column = bColOffset;
            AddAndStore(&C(row, column), r4c0);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c1);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c2);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c3);
            column_index += bwc::VectorWidth;
            AddAndStore(&C(row, column), r4c4);
        
        }
    };

}
