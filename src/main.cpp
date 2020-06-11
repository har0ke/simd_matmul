#include "Matrix.h"
#include <chrono>
#include <iostream>
#include <cassert>
#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/program_options.hpp>
#include <immintrin.h>

using namespace std::chrono;
namespace po = boost::program_options;

template<typename T>
Matrix<T> __attribute__ ((noinline)) naive(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2());
    assert(A.size2() == B.size1());

    for (int i = 0; i < A.size1(); i++) {
        for (int j = 0; j < B.size2(); j++) {
            for (int p = 0; p < B.size1(); p++) {
                C(i, j) += A(i, p) * B(p, j);
            }
        }
    }

    return C;
}

template<typename T>
Matrix<T> __attribute__ ((noinline)) naive_reordered(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2());
    assert(A.size2() == B.size1());
    for (int i = 0; i < A.size1(); i++) {
        for (int p = 0; p < B.size1(); p++) {
            for (int j = 0; j < B.size2(); j++) {
                C(i, j) += A(i, p) * B(p, j);
            }
        }
    }
    return C;
}

template<typename T>
Matrix<T> __attribute__ ((noinline)) register_blocking(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2());
    assert(A.size2() == B.size1());

    for (int i = 0; i < A.size1(); i++) {
        for (int p = 0; p < B.size1(); p++) {
            for (int j = 0; j < B.size2(); j++) {
                C(i, j) += A(i, p) * B(p, j);
            }
        }
    }

    return C;
}

template<typename T>
using BinaryMatrixOp = Matrix<T> (*)(const Matrix<T> &A, const Matrix<T> &B);

template<typename T>
Matrix<T> run_function(BinaryMatrixOp<T> f, const Matrix<T> &A, const Matrix<T> &B) {
    auto a = steady_clock::now();
    auto C = f(A, B);
    auto b = steady_clock::now();
    std::cout << "multiply: " << std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count() << "ms" << std::endl;
    return C;
}

struct __m256_block_wise_config {
    using FloatType = float;
    using VectorType = __m256;
    static constexpr auto LoadVector = _mm256_loadu_ps;
    static constexpr auto StoreVector = _mm256_storeu_ps;
    static constexpr auto BroadcastToVector = _mm256_broadcast_ss;
};

struct __m256d_block_wise_config {
    using FloatType = double;
    using VectorType = __m256d;
    static constexpr auto LoadVector = _mm256_loadu_pd;
    static constexpr auto StoreVector = _mm256_storeu_pd;
    static constexpr auto BroadcastToVector = _mm256_broadcast_sd;
};

template<
        // template parameter as struct: otherwise some warning about losing alignment information warning
        typename BlockWiseConfig = __m256_block_wise_config,
        unsigned numRows = 3, unsigned numColumns_width = 4
>
struct block_wise {
    using FloatType = typename BlockWiseConfig::FloatType;
    using VectorType = typename BlockWiseConfig::VectorType;
    static constexpr auto LoadVector = BlockWiseConfig::LoadVector;
    static constexpr auto StoreVector = BlockWiseConfig::StoreVector;
    static constexpr auto BroadcastToVector = BlockWiseConfig::BroadcastToVector;
    static constexpr size_t VectorWidth = sizeof(VectorType) / sizeof(FloatType);
    static constexpr auto AddAndStore = [](FloatType *memory, VectorType vector) { StoreVector(memory, LoadVector(memory) + vector); };

    Matrix<FloatType> operator()(const Matrix<FloatType> &A, const Matrix<FloatType> &B) {
        Matrix<FloatType> C(A.size1(), B.size2());
        int m = A.size1();
        int k = A.size2();
        int n = B.size2();
        int m_i = 0;
        for(; m_i + numRows <= m; m_i += numRows) { // row
            int n_i = 0;
            for(; n_i + numColumns_width * VectorWidth <= n; n_i += numColumns_width * VectorWidth) {
                handle_block(k, C, A, m_i, B, n_i);
            }
            // calculate remaining columns (like naive_reordered)
            if(n_i < n) {
                for (auto m_i_o = 0; m_i_o < numRows; ++m_i_o) {
                    for (int p = 0; p < k; ++p) {
                        for (auto n_i_rest = n_i; n_i_rest < n; ++n_i_rest) {
                            C(m_i + m_i_o, n_i_rest) += A(m_i + m_i_o, p) * B(p, n_i_rest);
                        }
                    }
                }
            }
        }
        // calculate remaining rows (like naive_reordered)
        for (; m_i < m; ++m_i) {
            for (int p = 0; p < k; p++) {
                for (int n_i = 0; n_i < n; ++n_i) {
                    C(m_i, n_i) += A(m_i, p) * B(p, n_i);
                }
            }
        }
        return C;

    }
    void __attribute__ ((noinline))  handle_block(int k, Matrix<FloatType> &C, const Matrix<FloatType> &A, int aRowOffset, const Matrix<FloatType> &B, int bColOffset) {

        // AVX2 has 16 registers
        // should be compiled as registers (total: regA * regB)
        VectorType CReg[numRows][numColumns_width] = {{0.0}};
        // iterate over dot-product terms
        for (int p = 0; p < k; p++) { // row index in B and column index in A (handling all rows/columns)
            // Perform the DOT product
            for (int bi = 0; bi < numColumns_width; bi++) { // column index in B (handling regsB * 'VectorWidth' columns)
                VectorType bb = LoadVector(&B(p, bColOffset + bi * VectorWidth));
                for (int ai = 0; ai < numRows; ai++) { // row index in A (handling regsA rows)
                    VectorType aa = BroadcastToVector(&A(aRowOffset + ai, p));
                    CReg[ai][bi] += aa * bb;
                }
            }
        }
        // total regA * regB + regB registers

        // Accumulate the results into C.
        for (int ai = 0; ai < numRows; ai++) {
            for (int bi = 0; bi < numColumns_width; bi++) {
                AddAndStore(&C(aRowOffset + ai, bColOffset + bi * VectorWidth), CReg[ai][bi]);
            }
        }
    }

};

template<typename FloatType>
struct block_wise_256;

template<>
struct block_wise_256<float> :
        public block_wise<__m256_block_wise_config> {};
template<>
struct block_wise_256<double> :
        public block_wise<__m256d_block_wise_config> {};


template<typename T>
Matrix<T> __attribute__ ((noinline)) block_wise_256_f(const Matrix<T> &A, const Matrix<T> &B) {
    return block_wise_256<T>()(A, B);
}

template<typename T>
Matrix<T> __attribute__ ((noinline)) boost_axpy_mul(const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2());
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

#define TEST_IF(test_function_name, function, A, B) {\
    if(test_function_name == #function) {\
        C = run_function(function, A, B);\
        use_result += C(0, 0);\
    }\
}

template<typename FloatType>
int main_work(const std::string &test_function_name, const std::string &input_folder, bool validate) {
    std::cout << "Running function '" << test_function_name << "'" << std::endl;
    std::srand(0);
    Matrix<FloatType> A;
    Matrix<FloatType> B;
    Matrix<FloatType> C;
    auto a = steady_clock::now();
    matrix_io<FloatType>::loadAB(A, B, input_folder);
    auto b = steady_clock::now();
    std::cout << "loading from file: " << std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count() << "ms" << std::endl;

    // use the result to prevent compiler to optimize...
    double use_result = 0;
    TEST_IF(test_function_name, naive, A, B)
    TEST_IF(test_function_name, naive_reordered, A, B)
    TEST_IF(test_function_name, block_wise_256_f, A, B)
    TEST_IF(test_function_name, boost_axpy_mul, A, B)
    TEST_IF(test_function_name, boost_blocked_mul_64, A, B)
    TEST_IF(test_function_name, boost_blocked_mul_256, A, B)
    TEST_IF(test_function_name, boost_mul, A, B)

    if(validate) {
        std::cout << "Validating matrix" << std::endl;
        auto C2 = boost_axpy_mul(A, B);
        if(C.size1() != C2.size1() || C.size2() != C2.size2())
            throw std::runtime_error("Result matrix has invalid size.");
        for(auto i = 0; i < C2.size1(); ++i) {
            for(auto j = 0; j < C2.size2(); ++j) {
                if(abs(C(i, j) - C2(i, j)) > 1e-3)
                    throw std::runtime_error("Result matrix is invalid.");
            }
        }
        std::cout << "Matrix seems fine" << std::endl;
    }
    std::cout << use_result << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" << std::endl;
    return use_result == 0 ? -1 : 0;
}

int main(int argc, char* argv[]) {
    po::options_description desc("Multiply two matrices");
    desc.add_options()
        ("input-folder", "folder containing matrices, following naming conventions; folder name:<n>x<k>x<m>; file name: <float|double><m>x<n>")
        ("validate", "validate matrix with boost")
            ("algorithm", po::value<std::string>(), "algorithm to execute")
            ("double", "use_double instead of float");
    po::positional_options_description p;
    p.add("input-folder", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
            options(desc).positional(p).run(), vm);
    po::notify(vm);

    std::string test_function_name = vm.count("algorithm") ? vm["algorithm"].as<std::string>() : DEFAULT_TEST_FUNCTION_NAME;

    if(vm.count("double")) {
        return main_work<double>(test_function_name, vm["input-folder"].as<std::string>(), vm.count("validate"));
    } else {
        return main_work<float>(test_function_name, vm["input-folder"].as<std::string>(), vm.count("validate"));
    }
}
