#ifndef MATRIXFRIENDOPERATORS_H
#define MATRIXFRIENDOPERATORS_H

#include "matrix.h"

template<typename T>
Matrix<T> operator +(const Matrix<T>& obj1, const Matrix<T>& obj2)
{
    if (obj1.getRowsNum() != obj2.getRowsNum() ||
            obj1.getColumnsNum() != obj2.getColumnsNum()) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, "Friend", __LINE__, ctime(&curTime));
    }

    const unsigned int n = obj1.getRowsNum(), m = obj1.getColumnsNum();
    Matrix<T> matrRes(obj1);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = obj1(i, j) + obj2(i, j);
        }
    }
    return matrRes;
}

template<typename T>
Matrix<T> operator +(const Matrix<T>& obj, const double num)
{
    unsigned int n = obj.getRowsNum(), m = obj.getColumnsNum();
    Matrix<T> matrRes(obj);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = obj(i, j) + num;
        }
    }
    return matrRes;
}

template<typename T>
Matrix<T> operator -(const Matrix<T>& obj1, const Matrix<T>& obj2)
{
    if (obj1.getRowsNum() != obj2.getRowsNum() ||
            obj1.getColumnsNum() != obj2.getColumnsNum()) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, "Friend", __LINE__, ctime(&curTime));
    }

    unsigned int n = obj1.getRowsNum(), m = obj1.getColumnsNum();
    Matrix<T> matrRes(obj1);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = obj1(i, j) - obj2(i, j);
        }
    }
    return matrRes;
}

template<typename T>
Matrix<T> operator -(const Matrix<T>& obj, const double num)
{
    unsigned int n = obj.getRowsNum(), m = obj.getColumnsNum();
    Matrix<T> matrRes(obj);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = obj(i, j) - num;
        }
    }
    return matrRes;
}

template<typename T>
Matrix<T> operator *(const Matrix<T>& obj1, const Matrix<T>& obj2)
{
    if (obj1.getColumnsNum() != obj2.getRowsNum()) {
        time_t curTime = time(nullptr);
        throw SizeErrors(__FILE__, "Friend", __LINE__, ctime(&curTime));
    }

    unsigned int n = obj1.getRowsNum(), m = obj1.getColumnsNum();
    Matrix<T> matrRes(obj1);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            for (unsigned int k = 0; k < m; k++) {
                matrRes[i][j] += obj1(i, k) * obj2(k, j);
            }
        }
    }
    return matrRes;
}

template<typename T>
Matrix<T> operator *(const Matrix<T>& obj, const double num)
{
    unsigned int n = obj.getRowsNum(), m = obj.getColumnsNum();
    Matrix<T> matrRes(obj);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = obj(i, j) * num;
        }
    }
    return matrRes;
}

template<typename T>
Matrix<T> operator /(const Matrix<T>& obj, const double num)
{
    if (num == 0.0) {
        time_t curTime = time(nullptr);
        throw NumError(__FILE__, "Friend", __LINE__, ctime(&curTime));
    }
    unsigned int n = obj.getRowsNum(), m = obj.getColumnsNum();
    Matrix<T> matrRes(obj);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m; j++) {
            matrRes[i][j] = obj(i, j) / num;
        }
    }
    return matrRes;
}

template<typename T>
ostream& operator <<(ostream& os, const Matrix<T>& obj)
{
    ConstIteratorMatr<T> it = obj.createIterator();
    if (it.isEnd() == true) {
        os << "Matrix is empty.\n\n";
        return os;
    }

    for (; it.isEnd() == false; it.next()) {
        os << *it << " ";
        if (it.isRowEnd() == true) {
            os << endl;
        }
    }

    /*for (auto elem : obj) {
        cout << elem << " ";
    }
    */

    os << endl;
    return os;
}


#endif // MATRIXFRIENDOPERATORS_H
