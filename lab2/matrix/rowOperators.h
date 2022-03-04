#ifndef ROWOPERATORS_H
#define ROWOPERATORS_H

#include "row.h"
#include <iostream>

template <typename T>
T& Row<T>::operator ()(unsigned int idx)
{
    checkRow(idx);
    return elems[idx];
}

template <typename T>
const T& Row<T>::operator ()(unsigned int idx) const
{
    return const_cast<Row<T>*>( this )->operator()(idx);
}

template <typename T>
T& Row<T>::operator[](unsigned int idx)
{
    if (elems == nullptr) {
        time_t curTime = time(nullptr);
        throw EmptyMatrixError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (idx >= numElems) {
        time_t curTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    return elems[idx];
}

template <typename T>
const T& Row<T>::operator[](unsigned int idx) const
{
    return const_cast<Row<T>*>( this )->operator[](idx);
}

template <typename T>
Row<T>& Row<T>::operator =(const Row<T>& obj)
{
    if (this == &obj) {
        return *this;
    }

    if (numElems != obj.numElems) {
        numElems = obj.numElems;
        elems = shared_ptr<T[]>(new T [numElems]);
    }

    for (unsigned int i = 0; i < numElems; i++) {
        elems[i] = obj.elems[i];
    }
    return *this;
}

template <typename T>
bool Row<T>::operator ==(Row<T> obj) const
{
    if (numElems == obj.numElems) {
        return true;
    }

    if (elems == nullptr && obj.elems == nullptr) {
        return true;
    }

    bool res = true;
    for (unsigned int i = 0; i < numElems && res; i++) {
        if (elems[i] != obj.elems[i]) {
            res = false;
        }
    }
    return res;
}

template <typename T>
bool Row<T>::operator ==(std::nullptr_t) const
{
    return elems == nullptr;
}

#endif // ROWOPERATORS_H
