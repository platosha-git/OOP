#ifndef ITERATORCONSTRUCTORS_H
#define ITERATORCONSTRUCTORS_H

#include "iterator.h"
#include <iostream>

template <typename T>
IteratorMatrBase<T>::IteratorMatrBase(const shared_ptr<Row<T>[]>& obj, unsigned int _nRows, unsigned int _nColumns) :
    current(obj),
    i(0), j(0),
    nRows(_nRows), nColumns(_nColumns)
{
}

template <typename T>
IteratorMatrBase<T>::IteratorMatrBase(const IteratorMatrBase<T>& it) :
    current(it.current),
    i(it.i), j(it.j),
    nRows(it.nRows), nColumns(it.nColumns)
{
}

template <typename T>
IteratorMatr<T>::IteratorMatr(const shared_ptr<Row<T>[]>& obj, unsigned int _nRows, unsigned int _nColumns) :
    IteratorMatrBase<T>(obj, _nRows, _nColumns)
{
}

template <typename T>
IteratorMatr<T>::IteratorMatr(const IteratorMatr<T>& it) :
    IteratorMatrBase<T> (it)
{
}

template <typename T>
IteratorMatr<T>::~IteratorMatr()
{
}

/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
ConstIteratorMatr<T>::ConstIteratorMatr(const shared_ptr<Row<T>[]>& obj, unsigned int _nRows, unsigned int _nColumns) :
    IteratorMatrBase<T> (obj, _nRows, _nColumns)
{
}

template <typename T>
ConstIteratorMatr<T>::ConstIteratorMatr(const ConstIteratorMatr<T>& it) :
    IteratorMatrBase<T> (it)
{
}

template <typename T>
ConstIteratorMatr<T>::~ConstIteratorMatr()
{
}

#endif // ITERATORCONSTRUCTORS_H
