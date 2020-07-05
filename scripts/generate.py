import os

code_template = """

namespace detail {

    template<typename BitWiseConfig, unsigned _NumRows, unsigned _NumColumnVectors>
    struct RegisterBlocking;
    
    template<typename BitWiseConfig>
    struct RegisterBlocking<BitWiseConfig, %d, %d> {
    
        typedef ExtendedBlockWiseConfig<BitWiseConfig> bwc;

        static constexpr auto AddAndStore = [](typename bwc::FloatType *memory, typename bwc::VectorType vector) {
            bwc::StoreVector(memory, bwc::LoadVector(memory) + vector);
        };

        static constexpr auto NumRows = 3;
        static constexpr auto NumColumns = 4 * bwc::VectorWidth;

        template<typename M1, typename M2, typename M3>
        static void __attribute__ ((noinline))
        handle_block(int k, M1 &C, const M2 &A, int aRowOffset, const M3 &B, int bColOffset) {
            
%s

            for (int p = 0; p < k; p++) {
%s
            }
            
%s
        
        }
    };

}
"""


def generate_rows(num_rows, num_columns):

    variables = ["c"]
    zero_variables = []
    loop_lines = []
    after_loop = []
    for row_index in range(num_rows):
        variables.append("r%d" % row_index)
        for column_index in range(num_columns):
            zero_variables.append("r%dc%d" % (row_index, column_index))

    for row_index in range(num_rows):
        loop_lines.append("r%d = bwc::BroadcastToVector(A(aRowOffset + %d, p));" % (row_index, row_index))

    for column_index in range(num_columns):
        loop_lines.append("c = bwc::LoadVector(&B(p, bColOffset + %d * bwc::VectorWidth));" % column_index)
        for row_index in range(num_rows):
            loop_lines.append("r%dc%d += r%d * c;" % (row_index, column_index, row_index))

    after_loop.append("size_t row = aRowOffset;")
    after_loop.append("size_t column;")
    for row_index in range(num_rows):
        after_loop.append("column = bColOffset;")
        for column_index in range(num_columns):
            after_loop.append("AddAndStore(&C(row, column), r%dc%d);" % (row_index, column_index))
            if column_index != num_columns - 1:
                after_loop.append("column += bwc::VectorWidth;")
        if row_index != num_rows - 1:
            after_loop.append("++row;")
    print(len(variables) + len(zero_variables))
    variables_lines = ["typename bwc::VectorType %s;" % variable for variable in variables]
    variables_lines += ["typename bwc::VectorType %s;" % variable for variable in zero_variables]
    variables_lines += [variable + " = bwc::XOR(" + variable + ", " + variable + ");" for variable in zero_variables]

    variables_code = "\n".join("            " + line for line in variables_lines)
    loop_code = "\n".join("                " + line for line in loop_lines)
    after_loop_code = "\n".join("            " + line for line in after_loop)

    return code_template % (num_rows, num_columns, variables_code, loop_code, after_loop_code)


max_register_count = 32

extra_registers = 1


def get_initial_column_vectors(rows, registers):
    if rows == 0:
        return 0
    result = int (float(registers - extra_registers - rows) / rows)
    if extra_registers + rows + rows * (result + 1) <= registers:
        return result + 1
    return result


def get_initial_rows(registers):
    for rows in reversed(range(registers)):
        if extra_registers + rows + rows * rows <= registers:
            return rows
    return 0


fn = os.path.join(os.path.dirname(__file__), "..", "src/register_blocking/detail/manual.h")
with open(fn, "w") as f:
    for rows in range(1, get_initial_rows(max_register_count) + 1):
        for columns in range(1, get_initial_column_vectors(rows, max_register_count) + 1):
            f.write(generate_rows(rows, columns))