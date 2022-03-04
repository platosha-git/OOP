#ifndef ROWMETHODS_H
#define ROWMETHODS_H

#include "row.h"
#include "rowBaseFunc.h"

template <typename T>
unsigned int Row<T>::getElemsNum() const
{
    return numElems;
}

template <typename T>
void Row<T>::setElem(unsigned int idx, const T& elem)
{
    checkRow();
    elems[idx] = elem;
}

template <typename T>
T& Row<T>::getElem(unsigned int idx)
{
    checkRow();
    return elems[idx];
}

template <typename T>
const T& Row<T>::getElem(unsigned int idx) const
{
    return const_cast<Row<T>*>( this )->getElem(idx);
}

#endif // ROWMETHODS_H
