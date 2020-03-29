#include "matrix.h"

Matrix::Row::Row(const size_t col)
{
    columns = col;
    a = nullptr;//new int[columns];
    //for(int i=0;i<columns;i++)
    //a[i]=0;
    //std::cout<<"createrow"<<std::endl;
}
Matrix::Row::Row(const size_t col, int* val)
{
    columns = col;
    a = val;//new int[columns];
    //for(int i=0;i<columns;i++)
    //a[i]=0;
    //std::cout<<"createrow"<<std::endl;
}
Matrix::Row::~Row()
{
    //std::cout<<"destructbeg"<<std::endl;
    columns=0;
    //std::cout<<"destructrow"<<std::endl;
    //std::cout<<"destructend"<<std::endl;
}
const int& Matrix::Row::operator[](int ncolumn) const
{
    if (ncolumn>columns)
        throw std::out_of_range("What a shame");
    return a[ncolumn];
}

int& Matrix::Row::operator[](int ncolumn)
{
    if (ncolumn>columns)
        throw std::out_of_range("What a shame");
    return a[ncolumn];
}

bool Matrix::Row::operator==(const Row rot) const
{
    for (int i=0;i<columns;i++)
    {
       if (a[i]!=rot.a[i])
            return false;
    }
    return true;
}
bool Matrix::Row::operator!=(const Row rot) const
{
    return !(*this==rot);
}

Matrix::Matrix(const size_t ra,const size_t col)
{
    rows=ra;
    columns=col;
    raw = new int[rows*columns];
    for(int i=0;i<rows*columns;i++)
    raw[i]=0;
    //std::cout<<"createmat"<<std::endl;
}
Matrix::~Matrix()
{
    //std::cout<<"destructmatbeg"<<std::endl;
    delete[] raw;
    rows=0;
    columns=0;
    //std::cout<<"deletemat"<<std::endl;
    //std::cout<<"destructmatend"<<std::endl;
}
const Matrix::Row Matrix::operator[](int nrow) const
{
    if (nrow>=rows)
        throw std::out_of_range("What a shame");
    const Matrix::Row strok(columns,raw+nrow*columns);
    return strok;
}

Matrix::Row Matrix::operator[](int nrow)
{
    if (nrow>=rows)
        throw std::out_of_range("What a shame");
    Matrix::Row strok(columns,raw+nrow*columns);
    return strok;
}

Matrix* Matrix::operator*=(int k)
{
    for (int i=0;i<rows*columns;i++)
        raw[i]*=k;
    return this;
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
