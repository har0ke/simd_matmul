//
// Created by oke on 05.06.20.
//

#include "Matrix.h"
#include <iostream>
#include <boost/filesystem.hpp>

template<typename FloatType>
Matrix<FloatType> random_matrix(size_t m, size_t n) {
    Matrix<FloatType> matrix(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix(i, j) = ((FloatType) std::rand()) / RAND_MAX;
        }
    }
    return matrix;
}

#include <boost/program_options.hpp>

namespace po = boost::program_options;

template<typename T>
void generate(size_t m, size_t k, size_t n) {
    auto A = random_matrix<T>(m, k);
    auto B = random_matrix<T>(k, n);

    Matrix<T> A_;
    Matrix<T> B_;

    matrix_io<T>::saveAB(A, B, ".");
}
int main(int argc, char *argv[]) {

    po::options_description desc("Generate matrices");
    desc.add_options()
            ("m",  po::value<size_t>(), "Size n")
            ("k",  po::value<size_t>(), "Size k")
            ("n",  po::value<size_t>(), "Size m")
            ("double", "use_double instead of float");
    po::positional_options_description p;
    p.add("m", 1);
    p.add("k", 1);
    p.add("n", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
            options(desc).positional(p).run(), vm);
    po::notify(vm);

    if(vm.count("double"))
        generate<double>(vm["m"].as<size_t>(), vm["k"].as<size_t>(), vm["n"].as<size_t>());
    else
        generate<float>(vm["m"].as<size_t>(), vm["k"].as<size_t>(), vm["n"].as<size_t>());
    return 0;
}
