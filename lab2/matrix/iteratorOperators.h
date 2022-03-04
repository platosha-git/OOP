#ifndef ITERATOROPERATORS_H
#define ITERATOROPERATORS_H

#include "iterator.h"
#include <iostream>

template <typename T>
IteratorMatr<T>& IteratorMatr<T>::operator++()
{
    this->next();
    return *this;
}

template <typename T>
IteratorMatr<T> IteratorMatr<T>::operator++(int)
{    
    IteratorMatr<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
IteratorMatr<T>& IteratorMatr<T>::operator--()
{
    this->previous();
    return *this;
}

template <typename T>
IteratorMatr<T> IteratorMatr<T>::operator--(int)
{
    IteratorMatr<T> it(*this);
    --(*this);
    return it;
}

template <typename T>
T& IteratorMatr<T>::operator *()
{
    checkIterator(__LINE__);
    return this->current.lock()[this->i][this->j];
}

template <typename T>
const T& IteratorMatr<T>::operator *() const
{
    return const_cast<IteratorMatr<T>*>( this )->operator*();
}

template <typename T>
T* IteratorMatr<T>::operator->()
{
    checkIterator(__LINE__);
    return &this->current.lock()[this->i][this->j];
}

template <typename T>
const T* IteratorMatr<T>::operator->() const
{
    return const_cast<IteratorMatr<T>*>( this )->operator->();
}

template <typename T>
IteratorMatr<T>& IteratorMatr<T>::operator=(const IteratorMatr<T>& it)
{
    if (this != &it) {
        this->current = it.current;
        this->i = it.i; this->j = it.j;
        this->nRows = it.nRows; this->nColumns = it.nColumns;
    }
    return *this;
}

template <typename T>
bool IteratorMatr<T>::operator ==(const IteratorMatr& it) const
{
    if (this->current.lock() == it.current.lock() &&
            this->i == it.i && this->j == it.j) {
        return true;
    }
    return false;
}

template <typename T>
bool IteratorMatr<T>::operator !=(const IteratorMatr& it) const
{
    if (this->current.lock() == it.current.lock() &&
            this->i == it.i && this->j == it.j) {
        return false;
    }
    return true;
}

template <typename T>
IteratorMatr<T>::operator bool() const
{
    checkIterator(__LINE__);
    if (this->nRows == 0 || this->nColumns == 0 || this->i < 0 || this->j < 0)
        return false;
    return true;
}

///////////////////////////////////////////////////////////////

template <typename T>
const T& ConstIteratorMatr<T>::operator* () const
{
    checkConstIterator(__LINE__);
    return this->current.lock()[this->i][this->j];
}

template <typename T>
const T* ConstIteratorMatr<T>::operator->() const
{
    checkConstIterator(__LINE__);
    return &this->current.lock()[this->i][this->j];
}

template <typename T>
ConstIteratorMatr<T>& ConstIteratorMatr<T>::operator=(const ConstIteratorMatr<T> &it)
{
    if (this != &it) {
        this->current = it.current;
        this->i = it.i; this->j = it.j;
        this->nRows = it.nRows; this->nColumns = it.nColumns;
    }
    return *this;
}

template <typename T>
bool ConstIteratorMatr<T>::operator ==(const ConstIteratorMatr& it) const
{
    if (this->current.lock() == it.current.lock() &&
            this->i == it.i && this->j == it.j) {
        return true;
    }
    return false;
}

template <typename T>
bool ConstIteratorMatr<T>::operator !=(const ConstIteratorMatr& it) const
{
    if (this->current.lock() == it.current.lock() &&
            this->i == it.i && this->j == it.j) {
        return false;
    }
    return true;
}

template <typename T>
ConstIteratorMatr<T>::operator bool() const
{
    checkConstIterator(__LINE__);
    if (this->nRows == 0 || this->nColumns == 0 || this->i < 0 || this->j < 0)
        return false;
    return true;
}

#endif // ITERATOROPERATORS_H
