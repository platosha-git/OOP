#ifndef ROWCONSTRUCTORS_H
#define ROWCONSTRUCTORS_H

#include "row.h"
#include <iostream>

template <typename T>
Row<T>::Row() :
    elems(nullptr),
    numElems(0)
{
}

template <typename T>
Row<T>::Row(unsigned int _numElems) :
    elems(nullptr),
    numElems(_numElems)
{
    elems = shared_ptr<T[]>(new T [numElems]);
    if (elems == nullptr) {
        time_t curTime = time(nullptr);
        throw AllocationError(__FILE__, "Row", __LINE__, ctime(&curTime));
    }

    for (unsigned int i = 0; i < numElems; i++) {
        elems[i] = 0;
    }
}

template <typename T>
Row<T>::Row(const Row<T>& obj) :
    elems(nullptr),
    numElems(0)
{
    if (obj.elems == nullptr) {
        return;
    }

    numElems = obj.numElems;

    elems = shared_ptr<T[]>(new T [numElems]);
    if (elems == nullptr) {
        time_t curTime = time(nullptr);
        throw AllocationError(__FILE__, "Row", __LINE__, ctime(&curTime));
    }

    for (unsigned int i = 0; i < numElems; i++) {
        elems[i] = obj.elems[i];
    }
}

template <typename T>
Row<T>::Row(Row<T>&& obj) :
    elems(obj.elems),
    numElems(obj.numElems)
{
    obj.elems = nullptr;
}

template <typename T>
Row<T>::~Row()
{
}

#endif // ROWCONSTRUCTORS_H
