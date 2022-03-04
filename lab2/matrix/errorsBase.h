#ifndef ERRORSBASE_H
#define ERRORSBASE_H

#include <string.h>
#include <exception>
#include <iostream>
using namespace std;

class MatrixErrors : public std::exception
{
public:
    explicit MatrixErrors(const string& fileName,
                            const string& className,
                            const int numLine,
                            const char* curTime,
                            const string& curInfo);

    virtual const char *what() const noexcept override
    {
        return errInfo.c_str();
    }

protected:
    string errInfo;
};

MatrixErrors::MatrixErrors(const string& fileName, const string& className,
                            const int numLine, const char* curTime, const string& curInfo)
{
    errInfo = "\nException in: \nFile: " + fileName + "\nClass: " + className + "\nLine: " +
                to_string(numLine) + "\nAt time: " + curTime + "Exception: " + curInfo;
}

#endif // ERRORSBASE_H
