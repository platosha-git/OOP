#ifndef MATRIXBASEFUNC_H
#define MATRIXBASEFUNC_H

#include "row.h"
#include "matrix.h"

template <typename T>
void Matrix<T>::allocateMatr()
{
    shared_ptr<Row<T>[]> matrTemp = nullptr;
    allocateMatr(&matrTemp, numRows, numColumns);
    matr = matrTemp;
}

template <typename T>
void Matrix<T>::allocateMatr(shared_ptr<Row<T>[]>* matr, unsigned int numRows, unsigned int numColumns)
{
    *matr = shared_ptr<Row<T>[]>(new Row<T> [numRows]);
    if (*matr == nullptr) {
        time_t curTime = time(nullptr);
        throw AllocationError(__FILE__, "Matrix", __LINE__, ctime(&curTime));
    }

    for (unsigned int i = 0; i < numRows; i++) {
        (*matr)[i] = Row<T> (numColumns);
        if ((*matr)[i] == nullptr) {
            time_t curTime = time(nullptr);
            throw AllocationError(__FILE__, "Matrix", __LINE__, ctime(&curTime));
        }
    }
}

template <typename T>
void Matrix<T>::initializeMatr(const T& elem)
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] = elem;
        }
    }
}

template <typename T>
void Matrix<T>::freeMatr()
{
    matr = nullptr;
    numRows = 0;
    numColumns = 0;
}

template <typename T>
void Matrix<T>::checkMatrix(unsigned int i, unsigned int j) const
{
    if (matr == nullptr) {
        time_t curTime = time(nullptr);
        throw EmptyMatrixError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (i >= numRows || j >= numColumns) {
        time_t curTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}

template <typename T>
IteratorMatr<T> Matrix<T>::createIterator()
{
    return IteratorMatr<T>(matr, numRows, numColumns);
}

template <typename T>
ConstIteratorMatr<T> Matrix<T>::createIterator() const
{
    return ConstIteratorMatr<T>(matr, numRows, numColumns);
}

template <typename T>
IteratorMatr<T> Matrix<T>::begin()
{
    return IteratorMatr<T>(matr, numRows, numColumns);
}

template <typename T>
ConstIteratorMatr<T> Matrix<T>::begin() const
{
    return ConstIteratorMatr<T>(matr, numRows, numColumns);
}

template <typename T>
IteratorMatr<T> Matrix<T>::end()
{
    IteratorMatr<T> it(matr, numRows, numColumns);
    it.end();
    return it;
}

template <typename T>
ConstIteratorMatr<T> Matrix<T>::end() const
{
    ConstIteratorMatr<T> it(matr, numRows, numColumns);
    it.end();
    return it;
}

template <typename T>
ConstIteratorMatr<T> Matrix<T>::c_begin() const
{
    return ConstIteratorMatr<T>(matr, numRows, numColumns);
}

template <typename T>
ConstIteratorMatr<T> Matrix<T>::c_end() const
{
    ConstIteratorMatr<T> it(matr, numRows, numColumns);
    it.end();
    return it;
}

#endif // MATRIXBASEFUNC_H
