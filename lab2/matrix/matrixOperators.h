#ifndef MATRIXOPERATORS_H
#define MATRIXOPERATORS_H

#include "matrix.h"
#include "matrixBaseFunc.h"
#include "iteratorConstructors.h"
#include "iteratorOperators.h"
#include "iteratorMethods.h"

template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& obj)
{
    if (this == &obj) {
        return *this;
    }

    if (numRows != obj.numRows || numColumns != obj.numColumns) {
        numRows = obj.numRows;
        numColumns = obj.numColumns;

        shared_ptr<Row<T>[]> matrTemp = nullptr;
        allocateMatr(&matrTemp, numRows, numColumns);
        freeMatr();
        matr = matrTemp;
    }

    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] = obj.matr[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(Matrix<T>&& obj)
{
    if (this == &obj) {
        return *this;
    }

    matr = obj.matr;
    numRows = obj.numRows;
    numColumns = obj.numColumns;

    obj.matr = nullptr;

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& obj) const
{
    if (numRows != obj.getRowsNum() || numColumns != obj.getColumnsNum()) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    const unsigned int n = obj.getRowsNum(), m = obj.getColumnsNum();
    Matrix<T> matrRes(n, m);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = matr[i][j] + obj(i, j);
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator +=(const Matrix<T>& obj)
{
    if (numRows != obj.numRows || numColumns != obj.numColumns) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] += obj.matr[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator +(const double num) const
{
    Matrix<T> matrRes(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matrRes.matr[i][j] = matr[i][j] + num;
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator +=(const double num)
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] += num;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator -(const Matrix<T>& obj) const
{
    if (numRows != obj.getRowsNum() || numColumns != obj.getColumnsNum()) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    const unsigned int n = obj.getRowsNum(), m = obj.getColumnsNum();
    Matrix<T> matrRes(n, m);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes.matr[i][j] = matr[i][j] - obj(i, j);
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator -=(const Matrix<T>& obj)
{
    if (numRows != obj.numRows || numColumns != obj.numColumns) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] -= obj.matr[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator -(const double num) const
{
    Matrix<T> matrRes(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matrRes.matr[i][j] = matr[i][j] - num;
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator -=(const double num)
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] -= num;
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& obj) const
{
    if (numColumns != obj.numRows) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    Matrix<T> matrRes(numRows, obj.numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < obj.numColumns; j++) {
            for (unsigned int k = 0; k < numColumns; k++) {
                matrRes.matr[i][j] += matr[i][k] * obj.matr[k][j];
            }
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(const Matrix<T>& obj)
{
    if (numColumns != obj.numRows) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    Matrix<T> matrRes(numRows, obj.numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < obj.numColumns; j++) {
            for (unsigned int k = 0; k < numColumns; k++) {
                matrRes.matr[i][j] += matr[i][k] * obj.matr[k][j];
            }
        }
    }

    *this = matrRes;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(double num) const
{
    Matrix<T> matrRes(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matrRes.matr[i][j] = matr[i][j] * num;
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(double num)
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] *= num;
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator /(double num) const
{
    if (num == 0.0) {
        time_t curTime = time(nullptr);
        throw NumError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Matrix<T> matrRes(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matrRes.matr[i][j] = matr[i][j] / num;
        }
    }
    return matrRes;
}

template <typename T>
Matrix<T>& Matrix<T>::operator /=(double num)
{
    if (num == 0.0) {
        time_t curTime = time(nullptr);
        throw NumError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] /= num;
        }
    }
    return *this;
}

template <typename T>
T& Matrix<T>::operator()(unsigned int i, unsigned int j)
{
    checkMatrix(i, j);
    return matr[i][j];
}

template <typename T>
const T& Matrix<T>::operator()(unsigned int i, unsigned int j) const
{
    return const_cast<Matrix<T>*>( this )->operator()(i, j);
}

template <typename T>
Row<T>& Matrix<T>::operator[](unsigned int idx)
{
    if (idx > numRows) {
        time_t curTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    return matr[idx];
}

template <typename T>
const Row<T>& Matrix<T>::operator[](unsigned int idx) const
{
    return const_cast<Matrix<T>*>( this )->operator[](idx);
}

template <typename T>
bool Matrix<T>::areEqual(const Matrix<T>& obj) const
{
    if (numRows != obj.numRows || numColumns != obj.numColumns) {
        return false;
    }

    if (matr == obj.matr) {
        return true;
    }

    bool res = true;
    for (unsigned int i = 0; i < numRows && res; i++) {
        for (unsigned int j = 0; j < numColumns && res; j++) {
            if (matr[i][j] != obj.matr[i][j]) {
                res = false;
            }
        }
    }
    return res;
}

template <typename T>
bool Matrix<T>::operator ==(const Matrix<T>& obj) const
{
    if (numRows != obj.numRows || numColumns != obj.numColumns) {
        return false;
    }

    if (matr == obj.matr) {
        return true;
    }

    bool res = true;
    for (unsigned int i = 0; i < numRows && res; i++) {
        for (unsigned int j = 0; j < numColumns && res; j++) {
            if (matr[i][j] != obj.matr[i][j]) {
                res = false;
            }
        }
    }
    return res;
}

template <typename T>
bool Matrix<T>::operator !=(const Matrix<T>& obj) const
{
    if (numRows != obj.numRows || numColumns != obj.numColumns) {
        return true;
    }

    if (matr == obj.matr) {
        return false;
    }

    bool res = true;
    for (unsigned int i = 0; i < numRows && res; i++) {
        for (unsigned int j = 0; j < numColumns && res; j++) {
            if (matr[i][j] == obj.matr[i][j]) {
                res = false;
            }
        }
    }
    return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator ^(unsigned int num)
{
    if (numRows != numColumns) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (num == 0) {
        initializeMatr(1);
        return *this;
    }

    const Matrix<T> matrRes(*this);
    for (unsigned int i = 0; i < num - 1; i++) {
        *this *= matrRes;
    }
    return *this;
}

#endif // MATRIXOPERATORS_H
