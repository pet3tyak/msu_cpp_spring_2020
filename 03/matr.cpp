#include "matrix.h"

Matrix::Row::Row(const size_t col)
{
    columns = col;
    a = nullptr;
}
Matrix::Row::Row(const size_t col, int* val)
{
    columns = col;
    a = val;
}
Matrix::Row::~Row()
{
    columns=0;
}
const int& Matrix::Row::operator[](size_t ncolumn) const
{
    if (ncolumn>columns)
        throw std::out_of_range("What a shame");
    return a[ncolumn];
}

int& Matrix::Row::operator[](size_t ncolumn)
{
    if (ncolumn>columns)
        throw std::out_of_range("What a shame");
    return a[ncolumn];
}

Matrix::Matrix(const size_t ra,const size_t col)
{
    rows=ra;
    columns=col;
    raw = new int[rows*columns];
    for(int i=0;i<rows*columns;i++)
        raw[i]=0;
}
Matrix::~Matrix()
{
    delete[] raw;
    rows=0;
    columns=0;
}
const Matrix::Row Matrix::operator[](size_t nrow) const
{
    if (nrow>=rows)
        throw std::out_of_range("What a shame");
    const Matrix::Row strok(columns,raw+nrow*columns);
    return strok;
}

Matrix::Row Matrix::operator[](size_t nrow)
{
    if (nrow>=rows)
        throw std::out_of_range("What a shame");
    Matrix::Row strok(columns,raw+nrow*columns);
    return strok;
}

Matrix& Matrix::operator*=(int k)
{
    for (int i=0;i<rows*columns;i++)
        raw[i]*=k;
    return *this;
}
int Matrix::getrows() const
{
    return rows;
}
int Matrix::getcolumns() const
{
    return columns;
}
bool Matrix::operator==(const Matrix& Mat) const
{
    if (this == &Mat)
        return true;
    if(rows!=Mat.rows || columns!=Mat.columns)
        return false;
    for (int i=0;i<rows*columns;i++)
    {
        if (raw[i]!=Mat.raw[i])
            return false;
    }
    return true;
}
bool Matrix::operator!=(const Matrix& Mat) const
{
    return !(*this==Mat);
}
