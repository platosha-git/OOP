#ifndef ROW_H
#define ROW_H

#include <memory>
#include "errors.h"
using namespace std;

template <typename T>
class Matrix;

template <typename T>
class Row
{
    friend class Matrix<T>;

public:
    virtual ~Row();

    unsigned int getElemsNum() const;

    void setElem(unsigned int idx, const T& elem);

    T& operator ()(unsigned int idx);
    const T& operator ()(unsigned int idx) const;
    T& operator [](unsigned int idx);
    const T& operator [](unsigned int idx) const;
    T& getElem(unsigned int idx);
    const T& getElem(unsigned int idx) const;

    Row<T>& operator =(const Row<T>& obj);

    bool operator ==(Row<T> obj) const;
    bool operator ==(std::nullptr_t) const;

private:
    Row();
    Row(unsigned int _numElems);
    Row(const Row<T>& obj);
    Row(Row<T>&& obj);

    shared_ptr<T[]> elems;
    unsigned int numElems;

    void allocateRow();
    void initializeRow(const T& elem);
    void freeRow();
    void checkRow(unsigned int i) const;
};

#endif // ROW_H
