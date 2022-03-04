#ifndef MATRIXBASE_H
#define MATRIXBASE_H

class MatrixBase
{
public:
    virtual unsigned int getRowsNum() const = 0;
    virtual unsigned int getColumnsNum() const = 0;
};

#endif // MATRIXBASE_H
