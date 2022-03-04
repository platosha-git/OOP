#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <memory>
#include <iostream>
using namespace std;

#include "matrixBase.h"
#include "iterator.h"
#include "rowConstructors.h"
#include "rowOperators.h"
#include "rowMethods.h"

template <typename T>
class Matrix : public MatrixBase
{
public:
    //Constructors
    Matrix(unsigned int _numRows, unsigned int _numColumns);
    explicit Matrix(initializer_list<T> list);
    explicit Matrix(initializer_list<initializer_list<T>> list);
    Matrix(IteratorMatr<T>& begin, IteratorMatr<T>& end);
    explicit Matrix(const Matrix<T>& obj);
    Matrix(Matrix<T>&& obj);
    virtual ~Matrix();


    Matrix<T>& operator =(const Matrix<T>& obj);
    Matrix<T>& operator =(Matrix<T>&& obj);

    void sum(const Matrix<T>& obj);
    Matrix<T> operator +(const Matrix<T>& obj) const;
    Matrix<T>& operator +=(const Matrix<T>& obj);

    void sum(double num);
    Matrix<T> operator +(double num) const;
    Matrix<T>& operator +=(double num);

    void sub(const Matrix<T>& obj);
    Matrix<T> operator -(const Matrix<T>& obj) const;
    Matrix<T>& operator -=(const Matrix<T>& obj);

    void sub(double num);
    Matrix<T> operator -(double num) const;
    Matrix<T>& operator -=(double num);

    void mul(const Matrix<T>& obj);
    Matrix<T> operator *(const Matrix<T>& obj) const;
    Matrix<T>& operator *=(const Matrix<T>& obj);

    void mul(double num);
    Matrix<T> operator *(double num) const;
    Matrix<T>& operator *=(double num);

    void div(double num);
    Matrix<T> operator /(double num) const;
    Matrix<T>& operator /=(double num);

    void pow(unsigned int num);
    Matrix<T>& operator ^(unsigned int num);

    bool areEqual(const Matrix<T>& obj) const;
    bool operator ==(const Matrix<T>& obj) const;
    bool operator !=(const Matrix<T>& obj) const;

    void setElem(unsigned int i, unsigned int j, const T& elem);
    T& operator()(unsigned int i, unsigned int j);
    const T& operator()(unsigned int i, unsigned int j) const;
    Row<T>& operator [](unsigned int idx);
    const Row<T>& operator [](unsigned int idx) const;
    T& getElem(unsigned int i, unsigned int j);
    const T& getElem(unsigned int i, unsigned int j) const;

    void swapRows(unsigned int r1, unsigned int r2);
    void swapColumns(unsigned int c1, unsigned int c2);

    //MatrixBase
    virtual unsigned int getRowsNum() const override;
    virtual unsigned int getColumnsNum() const override;
    bool isSquare() const;

    void output() const;
    void transponse();
    double determinant() const;
    void inverse();

    IteratorMatr<T> createIterator();
    ConstIteratorMatr<T> createIterator() const;

    IteratorMatr<T> begin();
    ConstIteratorMatr<T> begin() const;

    IteratorMatr<T> end();
    ConstIteratorMatr<T> end() const;

    ConstIteratorMatr<T> c_begin() const;
    ConstIteratorMatr<T> c_end() const;

    //std::ostream& operator <<(std::ostream& os, const Matrix<T>& obj);

private:
    shared_ptr<Row<T>[]> matr;
    unsigned int numRows;
    unsigned int numColumns;

    void allocateMatr();
    void initializeMatr(const T& elem);
    void freeMatr();
    void checkMatrix(unsigned int i, unsigned int j) const;
    static void allocateMatr(shared_ptr<Row<T>[]>* matr, unsigned int numRows, unsigned int numColumns);
};

#endif // MATRIX_H
