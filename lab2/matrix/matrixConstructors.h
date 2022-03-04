#ifndef MATRIXCONSTRUCTORS_H
#define MATRIXCONSTRUCTORS_H

#include "matrix.h"
#include "matrixBaseFunc.h"

template <typename T>
Matrix<T>::Matrix(unsigned int _numRows, unsigned int _numColumns) :
    matr(nullptr),
    numRows(_numRows),
    numColumns(_numColumns)
{
    allocateMatr();
    initializeMatr(0);
}

template <typename T>
Matrix<T>::Matrix(initializer_list<T> list) :
    matr(nullptr),
    numRows(1),
    numColumns(list.size())
{
    allocateMatr();

    unsigned int i = 0;
    for (T element : list) {
        matr[0][i] = element;
        i++;
    }
}

template <typename T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> list) :
    matr(nullptr),
    numRows(list.size()),
    numColumns(list.begin()->size())
{
    allocateMatr();

    unsigned int i = 0, j = 0;
    for (auto& l : list) {
        for (auto& v : l) {
            matr[i][j] = v;
            j++;
        }
        j = 0;
        i++;
    }
}

template <typename T>
Matrix<T>::Matrix(IteratorMatr<T>& begin, IteratorMatr<T>& end)
{
    numRows = begin.nRows;
    numColumns = begin.nColumns;
    allocateMatr();

    unsigned int i = 0, j = 0;
    for (; begin != end && !begin.isEnd(); begin++) {
        matr[i][j] = begin.value();
        if (begin.isRowEnd()) {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& obj) :
    matr(nullptr),
    numRows(0),
    numColumns(0)
{
    if (obj.matr == nullptr) {
        return;
    }

    numRows = obj.numRows; numColumns = obj.numColumns;
    allocateMatr();

    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] = obj.matr[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& obj) :
    matr(obj.matr),
    numRows(obj.numRows),
    numColumns(obj.numColumns)
{
    obj.matr = nullptr;
    obj.numRows = 0;
    obj.numColumns = 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
}

#endif // MATRIXCONSTRUCTORS_H
