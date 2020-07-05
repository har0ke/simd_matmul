#include "Matrix.h"
#include <chrono>
#include <iostream>
#include <cassert>
#include <boost/program_options.hpp>
#include "register_blocking/BlockWise.h"
#include "Boost.h"
#include "Naive.h"
#include "DevideAndConquer.h"
#include "BLASMul.h"
using namespace std::chrono;
namespace po = boost::program_options;

template<typename T>
using BinaryMatrixOp = void (*)(Matrix<T> &C, const Matrix<T> &A, const Matrix<T> &B);

template<typename T>
Matrix<T> run_function(BinaryMatrixOp<T> f, const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> C(A.size1(), B.size2(), 0);
    auto a = steady_clock::now();
    f(C, A, B);
    auto b = steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(b - a).count();
    if (ms > 1000) {
        std::cout << "multiply: " << ms / 1000. << "s" << std::endl;
    } else {
        std::cout << "multiply: " << ms << "ms" << std::endl;
    }
    return C;
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

    TEST_IF(test_function_name, naive_reordered, A, B)
    TEST_IF(test_function_name, block_wise_sse, A, B)
    TEST_IF(test_function_name, block_wise_avx2, A, B)

#ifdef WITH_AVX512
    TEST_IF(test_function_name, block_wise_avx512, A, B)
#endif

    TEST_IF(test_function_name, boost_axpy_mul, A, B)
    TEST_IF(test_function_name, divide_and_conquer_block_sse, A, B)
    TEST_IF(test_function_name, divide_and_conquer_block_avx2, A, B)

#ifdef WITH_AVX512
    TEST_IF(test_function_name, divide_and_conquer_block_avx5120, A, B)
    TEST_IF(test_function_name, divide_and_conquer_block_avx5121, A, B)
    TEST_IF(test_function_name, divide_and_conquer_block_avx5122, A, B)
    TEST_IF(test_function_name, divide_and_conquer_block_avx5123, A, B)

    TEST_IF(test_function_name, divide_and_conquer_block_avx512, A, B)
#endif

    TEST_IF(test_function_name, divide_and_conquer_naive_r1, A, B)
    TEST_IF(test_function_name, divide_and_conquer_naive_r2, A, B)
    TEST_IF(test_function_name, divide_and_conquer_naive_r3, A, B)
    TEST_IF(test_function_name, divide_and_conquer_naive_r4, A, B)
    TEST_IF(test_function_name, divide_and_conquer_naive_r5, A, B)
    TEST_IF(test_function_name, blas, A, B)

    if(validate) {
        std::cout << "Validating matrix" << std::endl;
        Matrix<FloatType> C2(A.size1(), B.size2(), 0);
        boost_axpy_mul(C2, A, B);
        if(C.size1() != C2.size1() || C.size2() != C2.size2())
            throw std::runtime_error("Result matrix has invalid size.");
        for(auto i = 0; i < C2.size1(); ++i) {
            for(auto j = 0; j < C2.size2(); ++j) {
                if(abs(C(i, j) - C2(i, j)) > 1e-1) {
                    std::cerr << i << ", " << j << " is wrong with values " << C(i, j) << ", " << C2(i, j) << std::endl;
                    exit(-1);
                }
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
