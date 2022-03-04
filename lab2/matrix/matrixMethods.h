#ifndef MATRIXMETHODS_H
#define MATRIXMETHODS_H

#define eps 0.000001

#include "matrix.h"
#include "matrixBaseFunc.h"

template <typename T>
void Matrix<T>::sum(const Matrix<T>& obj)
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
}

template <typename T>
void Matrix<T>::sum(double num)
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] += num;
        }
    }
}

template <typename T>
void Matrix<T>::sub(const Matrix<T>& obj)
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
}

template <typename T>
void Matrix<T>::sub(double num)
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] -= num;
        }
    }
}

template <typename T>
void Matrix<T>::mul(const Matrix<T>& obj)
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
}

template <typename T>
void Matrix<T>::mul(double num)
{
    Matrix<T> matrRes(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] *= num;
        }
    }
}

template <typename T>
void Matrix<T>::div(double num)
{
    Matrix<T> matrRes(numRows, numColumns);
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            matr[i][j] /= num;
        }
    }
}

template <typename T>
void Matrix<T>::pow(unsigned int num)
{
    if (numRows != numColumns) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (num == 0) {
        initializeMatr(1);
        return;
    }

    const Matrix<T> matrRes(*this);
    for (unsigned int i = 0; i < num - 1; i++) {
        *this *= matrRes;
    }
}

template <typename T>
void Matrix<T>::setElem(unsigned int i, unsigned int j, const T& elem)
{
    checkMatrix(i, j);
    matr[i][j] = elem;
}

template <typename T>
T& Matrix<T>::getElem(unsigned int i, unsigned int j)
{
    checkMatrix(i, j);
    return matr[i][j];
}

template <typename T>
const T& Matrix<T>::getElem(unsigned int i, unsigned int j) const
{
    return const_cast<Matrix<T>*>( this )->getElem(i, j);
}

template <typename T>
bool Matrix<T>::isSquare() const
{
    return numRows == numColumns;
}

template <typename T>
unsigned int Matrix<T>::getRowsNum() const
{
    return numRows;
}

template <typename T>
unsigned int Matrix<T>::getColumnsNum() const
{
    return numColumns;
}

template <typename T>
void Matrix<T>::swapRows(unsigned int r1, unsigned int r2)
{
    if (r1 >= numRows || r2 >= numRows) {
        time_t curTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    /*Row<T> temp;
    temp = matr[r1];
    matr[r1] = matr[r2];
    matr[r2] = temp;
    */
}

template <typename T>
void Matrix<T>::swapColumns(unsigned int c1, unsigned int c2)
{
    if (c1 >= numColumns || c2 >= numColumns) {
        time_t curTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    for (unsigned int i = 0; i < numRows; i++) {
        swap(matr[c1], matr[c2]);
    }
}

template <typename T>
void Matrix<T>::output() const
{
    for (unsigned int i = 0; i < numRows; i++) {
        for (unsigned int j = 0; j < numColumns; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void Matrix<T>::transponse()
{
    shared_ptr<Row<T>[]> matrTemp = nullptr;
    const unsigned int nTemp = numColumns, mTemp = numRows;
    allocateMatr(&matrTemp, nTemp, mTemp);

    for (unsigned int i = 0; i < nTemp; i++) {
        for (unsigned int j = 0; j < mTemp; j++) {
            matrTemp[i][j] = matr[j][i];
        }
    }

    freeMatr();
    numRows = nTemp; numColumns = mTemp;
    matr = matrTemp;
}

template <typename T>
double Matrix<T>::determinant() const
{
    Matrix<T> temp(*this);
    if (numRows != numColumns) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    double det = 1;
    for (unsigned int i = 0; i < numRows; i++) {
        unsigned int k = i;
        for (unsigned int j= i + 1; j < numRows; j++) {
            if (abs(temp.matr[j][i]) > abs(temp.matr[k][i])) {
                k = j;
            }
        }

        if (abs (temp.matr[k][i]) < eps) {
            det = 0;
            break;
        }

        temp.swapRows(i, k);

        if (i != k) {
            det *= -1;
        }

        det *= temp.matr[i][i];
        for (unsigned int j = i + 1; j < numRows; j++) {
            temp.matr[i][j] /= temp.matr[i][i];
        }

        for (unsigned int j = 0; j < numRows; j++) {
            if (j != i && abs (temp.matr[j][i]) > eps) {
                for (unsigned int k = i + 1; k < numRows; k++) {
                    temp.matr[j][k] -= temp.matr[i][k] * temp.matr[j][i];
                }
            }
        }
    }

    return det;
}

template <typename T>
void Matrix<T>::inverse()
{
    const double det = this->determinant();
    if (det != 0.0) {
        this->transponse();
        for (unsigned int i = 0; i < numRows; i++) {
            for (unsigned int j = 0; j < numColumns; j++) {
                matr[i][j] /= det;
            }
        }
    }
}

#endif // MATRIXMETHODS_H
