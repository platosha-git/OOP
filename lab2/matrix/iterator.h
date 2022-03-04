#ifndef ITERATOR_H
#define ITERATOR_H

#include "row.h"

template <typename T>
class Matrix;

template <typename T>
class IteratorMatrBase : public iterator<input_iterator_tag, T>
{
    friend class Matrix<T>;

public:
    IteratorMatrBase(const shared_ptr<Row<T>[]>& obj, unsigned int _nRows, unsigned int _nColumns);
    IteratorMatrBase(const IteratorMatrBase<T>& it);
    virtual ~IteratorMatrBase() {}
    virtual void begin() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
    virtual void end() = 0;

protected:
    weak_ptr<Row<T>[]> current;
    unsigned int i; unsigned int j;
    unsigned int nRows; unsigned int nColumns;
};

template <typename T>
class IteratorMatr : public IteratorMatrBase<T>
{
public:
    //Constructors
    IteratorMatr(const shared_ptr<Row<T>[]>& obj, unsigned int _nRows, unsigned int _nColumns);
    IteratorMatr(const IteratorMatr<T>& it);
    virtual ~IteratorMatr();

    virtual void begin() override;

    virtual void next() override;
    IteratorMatr<T>& operator ++();
    IteratorMatr<T> operator ++(int);

    virtual void previous() override;
    IteratorMatr<T>& operator --();
    IteratorMatr<T> operator --(int);

    virtual void end() override;

    bool isEnd() const;
    bool isRowEnd() const;

    T value();
    const T value() const;
    T& operator* ();
    const T& operator* () const;

    T* operator->();
    const T* operator->() const;

    IteratorMatr<T>& operator=(const IteratorMatr<T>& it);

    bool operator==(const IteratorMatr& it) const;
    bool operator!=(const IteratorMatr& it) const;

    operator bool() const;

    bool checkIterator(int line) const;
};

template <typename T>
class ConstIteratorMatr : public IteratorMatrBase<T>
{
public:
    //Constructors
    ConstIteratorMatr(const shared_ptr<Row<T>[]>& obj, unsigned int _nRows, unsigned int _nColumns);
    ConstIteratorMatr(const ConstIteratorMatr<T>& it);
    ~ConstIteratorMatr();

    virtual void begin() override;
    virtual void next() override;
    virtual void previous() override;
    virtual void end() override;

    bool isEnd() const;
    bool isRowEnd() const;

    const T value() const;
    const T& operator* () const;

    const T* operator->() const;

    ConstIteratorMatr<T>& operator=(const ConstIteratorMatr<T> &it);

    bool operator ==(const ConstIteratorMatr& it) const;
    bool operator !=(const ConstIteratorMatr& it) const;

    operator bool() const;

    bool checkConstIterator(int line) const;
};

#endif // ITERATOR_H
