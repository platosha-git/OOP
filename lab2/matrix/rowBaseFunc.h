#ifndef ROWBASEFUNC_H
#define ROWBASEFUNC_H

#include "row.h"

template <typename T>
void AllocateRow(shared_ptr<T[]>* elems, unsigned int numElems)
{
    *elems = shared_ptr<T[]>(new T [numElems]);
    if (*elems == nullptr) {
        time_t curTime = time(nullptr);
        throw AllocationError(__FILE__, "Row", __LINE__, ctime(&curTime));
    }
}

template <typename T>
void Row<T>::allocateRow()
{
    shared_ptr<T[]> elemsTemp = nullptr;
    AllocateRow(&elemsTemp, numElems);
    elems = elemsTemp;
}

template <typename T>
void Row<T>::initializeRow(const T& elem)
{
    for (unsigned int i = 0; i < numElems; i++) {
        elems[i] = elem;
    }
}

template <typename T>
void Row<T>::freeRow()
{
    if (elems != nullptr) {
        delete[] elems;
    }
}

template <typename T>
void Row<T>::checkRow(unsigned int i) const
{
    if (elems == nullptr) {
        time_t curTime = time(nullptr);
        throw EmptyMatrixError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (i >= numElems) {
        time_t curTime = time(nullptr);
        throw IndexError(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}


#endif // ROWBASEFUNC_H
