#ifndef ITERATORMETHODS_H
#define ITERATORMETHODS_H

#include "iterator.h"
#include <iostream>

template <typename T>
void IteratorMatr<T>::begin()
{
    checkIterator(__LINE__);
    this->i = 0; this->j = 0;
}

template <typename T>
void IteratorMatr<T>::next()
{
    checkIterator(__LINE__);

    if (this->i < this->nRows) {
        if (this->isRowEnd() == true) {
            this->i++;
            this->j = 0;
        } else {
            this->j++;
        }
    }
}

template <typename T>
void IteratorMatr<T>::previous()
{
    if (this->current.expired() ||
            this->i > this->nRows || this->j > this->nColumns) {
        time_t curTime = time(nullptr);
        throw IteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (this->i > 0 || this->j > 0) {
        if (this->j == 0) {
            this->i--;
            this->j = this->nRows - 1;
        } else {
            this->j--;
        }
    }
}

template <typename T>
void IteratorMatr<T>::end()
{
    checkIterator(__LINE__);

    this->i = this->nRows;
    this->j = 0;
}

template <typename T>
bool IteratorMatr<T>::isEnd() const
{
    if (this->i == this->nRows && this->j == 0) {
        return true;
    }
    return false;
}

template <typename T>
bool IteratorMatr<T>::isRowEnd() const
{
    return (this->j == this->nColumns - 1);
}

template <typename T>
T IteratorMatr<T>::value()
{
    checkIterator(__LINE__);
    return this->current.lock()[this->i][this->j];
}

template <typename T>
const T IteratorMatr<T>::value() const
{
    return const_cast<IteratorMatr<T>*>( this )->value()();
}

template <typename T>
bool IteratorMatr<T>::checkIterator(int line) const
{
    if (this->current.expired() ||
            this->i >= this->nRows || this->j >= this->nColumns) {
        time_t curTime = time(nullptr);
        throw IteratorError(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    }
    return true;
}

//////////////////////////////////////////////////////////////////////////////

template <typename T>
void ConstIteratorMatr<T>::begin()
{
    checkConstIterator(__LINE__);
    this->i = 0; this->j = 0;
}

template <typename T>
void ConstIteratorMatr<T>::next()
{
    checkConstIterator(__LINE__);

    if (this->i < this->nRows) {
        if (this->isRowEnd() == true) {
            this->i++;
            this->j = 0;
        } else {
            this->j++;
        }
    }
}

template <typename T>
void ConstIteratorMatr<T>::previous()
{
    if (this->current.expired() ||
            this->i > this->nRows || this->j > this->nColumns) {
        time_t curTime = time(nullptr);
        throw IteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (this->i > 0 || this->j > 0) {
        if (this->j == 0) {
            this->i--;
            this->j = this->nRows - 1;
        } else {
            this->j--;
        }
    }
}

template <typename T>
void ConstIteratorMatr<T>::end()
{
    checkConstIterator(__LINE__);

    this->i = this->nRows;
    this->j = 0;
}

template <typename T>
bool ConstIteratorMatr<T>::isEnd() const
{
    if (this->i == this->nRows && this->j == 0) {
        return true;
    }
    return false;
}

template <typename T>
bool ConstIteratorMatr<T>::isRowEnd() const
{
    return (this->j == this->nColumns - 1);
}

template <typename T>
const T ConstIteratorMatr<T>::value() const
{
    checkConstIterator(__LINE__);
    return this->current.lock()[this->i][this->j];
}

template <typename T>
bool ConstIteratorMatr<T>::checkConstIterator(int line) const
{
    if (this->current.expired() ||
            this->i >= this->nRows || this->j >= this->nColumns) {
        time_t curTime = time(nullptr);
        throw IteratorError(__FILE__, typeid(*this).name(), line, ctime(&curTime));
    }
    return true;
}

#endif // ITERATORMETHODS_H
