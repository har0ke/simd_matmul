//
// Created by oke on 04.07.20.
//

#ifndef SMID_MATRIX_EXTENDEDBLOCKWISECONFIG_H
#define SMID_MATRIX_EXTENDEDBLOCKWISECONFIG_H

template<typename BlockWiseConfig>
struct ExtendedBlockWiseConfig {

    typedef typename BlockWiseConfig::FloatType FloatType;
    using VectorType = typename BlockWiseConfig::VectorType;

    static constexpr auto Registers = BlockWiseConfig::Registers;
    static constexpr auto LoadVector = BlockWiseConfig::LoadVector;
    static constexpr auto StoreVector = BlockWiseConfig::StoreVector;
    static constexpr auto XOR = BlockWiseConfig::XOR;
    static constexpr auto BroadcastToVector = BlockWiseConfig::BroadcastToVector;
    static constexpr size_t VectorWidth = sizeof(VectorType) / sizeof(FloatType);
    static constexpr auto AddAndStore = [](FloatType *memory, VectorType vector) {
        StoreVector(memory, LoadVector(memory) + vector);
    };
};

// maximize = (R * C) / (R + C) for  R + R * C < 16 => any fixed r -> largest C with < 16
// C = floor ((16 - R) / R)

// maximize = (R * C) / (R + C) for  1 + R + R * C < 16 => any fixed r -> largest C with < 16
// C = floor ((16 - R) / R)

unsigned constexpr extra_registers = 1;


constexpr unsigned GetInitialColumnVectors(unsigned R, unsigned Registers) {
    if (R == 0) return 0;
    auto result = (unsigned) ((double) (Registers - extra_registers - R) / (double) R);
    if (extra_registers + R + R * (result + 1) <= Registers)
        return result + 1;
    return result;
}

constexpr unsigned GetInitialRows(unsigned Registers) {
    for(unsigned R = Registers; R > 0; --R) {
        if(extra_registers + R + R * R <= Registers) {
            return R;
        }
    }
    return 0;
}

#endif //SMID_MATRIX_EXTENDEDBLOCKWISECONFIG_H
