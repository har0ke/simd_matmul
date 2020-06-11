//
// Created by oke on 05.06.20.
//

#ifndef SMID_MATRIX_Matrix_H
#define SMID_MATRIX_Matrix_H

#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/storage.hpp>
#include <boost/align/aligned_allocator.hpp>
#include <boost/filesystem.hpp>

template<typename T, size_t Alignment=64> // byte (512 bit)
using AlignedBoostMatrix = boost::numeric::ublas::matrix<T, boost::numeric::ublas::row_major,
        boost::numeric::ublas::unbounded_array<T, boost::alignment::aligned_allocator<T, Alignment>>>;

template<typename T, size_t Alignment=512 / sizeof(T)>
using Matrix = AlignedBoostMatrix<T, Alignment>;

template<typename T>
class matrix_io {
public:
    matrix_io() = delete;
    static void save(const Matrix<T> &matrix, const boost::filesystem::path &folder);
    static Matrix<T> load(const boost::filesystem::path & fn);
    static void loadAB(Matrix<T> &A, Matrix<T> &B, boost::filesystem::path folder);
    static boost::filesystem::path saveAB(const Matrix<T> &A, const Matrix<T> &B, boost::filesystem::path base_folder);
};

extern template class matrix_io<float>;
extern template class matrix_io<double>;

#endif //SMID_MATRIX_Matrix_H
