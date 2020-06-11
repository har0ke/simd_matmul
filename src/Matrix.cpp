//
// Created by oke on 05.06.20.
//
#include "Matrix.h"
#include <fstream>

template<typename T>
struct value_prefix;

template<>
struct value_prefix<double> {
    static constexpr auto prefix = "double";
};

template<>
struct value_prefix<float> {
    static constexpr auto prefix = "float";
};

template<typename T>
void matrix_io<T>::save(const Matrix<T> &matrix, const boost::filesystem::path &folder) {
    auto fn = folder / (value_prefix<T>::prefix + std::to_string(matrix.size1()) + "x" + std::to_string(matrix.size2()));
    std::ofstream f(fn.native());
    f.write((char * )&matrix(0, 0), sizeof(T) * matrix.size2() * matrix.size1());
    f.close();
}

template<typename T>
Matrix<T> matrix_io<T>::load(const boost::filesystem::path & fn) {
    if(!boost::filesystem::is_regular_file(fn)) {
        std::cerr << fn << std::endl;
        throw std::runtime_error("Is not a file");
    }

    std::string fileName = fn.filename().native();

    size_t startN = 0;
    while((fileName[startN] < 0 || fileName[startN] > '9') && startN < fn.size()) ++startN;
    if(startN == fileName.size()) throw;

    auto prefix = fileName.substr(0, startN);
    if(prefix != value_prefix<T>::prefix) throw;

    size_t endN = startN;
    while((fileName[endN] != 'x') && endN < fileName.size()) ++endN;
    if(endN == fileName.size()) throw;

    size_t m = std::stoul(fileName.substr(startN, endN - startN));
    size_t n = std::stoul(fileName.substr(endN + 1));

    Matrix<T> matrix(m, n);
    std::ifstream f(fn.native());
    f.read((char * )&matrix(0, 0), sizeof(T) * m * n);
    f.close();
    return matrix;
}

template<typename T>
void matrix_io<T>::loadAB(Matrix<T> &A, Matrix<T> &B, boost::filesystem::path folder) {
    if(!boost::filesystem::is_directory(folder))
        throw std::runtime_error("Is not a directory");

    std::string folderName = folder.filename().string();
    auto last_i = 0;
    size_t i;
    size_t sizes_i = 0;
    size_t sizes[3];
    while((i = folderName.find("x", last_i)) != std::string::npos) {
        if(sizes_i >= 2) throw;
        sizes[sizes_i] = std::stoul(folderName.substr(last_i, i - last_i));
        last_i = i + 1;
        ++sizes_i;
    }
    if(sizes_i != 2) throw;
    sizes[sizes_i] = std::stoul(folderName.substr(last_i));
    A = matrix_io<T>::load(folder /  (value_prefix<T>::prefix + std::to_string(sizes[0]) + "x" + std::to_string(sizes[1])));
    B = matrix_io<T>::load(folder / (value_prefix<T>::prefix + std::to_string(sizes[1]) + "x" + std::to_string(sizes[2])));
}

template<typename T>
boost::filesystem::path matrix_io<T>::saveAB(const Matrix<T> &A, const Matrix<T> &B, boost::filesystem::path base_folder) {
    auto folder = base_folder / (std::to_string(A.size1()) + "x" + std::to_string(A.size2()) + "x" + std::to_string(B.size2()));
    boost::filesystem::create_directories(folder);
    matrix_io::save(A, folder);
    matrix_io::save(B, folder);
    return folder;
}


template class matrix_io<float>;
template class matrix_io<double>;