#ifndef ERRORS_H
#define ERRORS_H

#include "errorsBase.h"

class AllocationError : public MatrixErrors
{
public:
    AllocationError(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Allocation Error.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class IndexError : public MatrixErrors
{
public:
    IndexError(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Index is out of range.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class SizeErrors : public MatrixErrors
{
public:
    SizeErrors(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Matrix size mismatch.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class ListInitError : public MatrixErrors
{
public:
    ListInitError(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Initialization by list is incorrect.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class EmptyMatrixError : public MatrixErrors
{
public:
    EmptyMatrixError(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Matrix is empty.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class NumError : public MatrixErrors
{
public:
    NumError(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Division by zero.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

class IteratorError : public MatrixErrors
{
public:
    IteratorError(const string& fileName, const string& className,
                    const int numLine, const char* curTime, const string& curInfo = "Iterator is incorrect.") :
    MatrixErrors(fileName, className, numLine, curTime, curInfo) {}

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }
};

#endif // ERRORS_H
