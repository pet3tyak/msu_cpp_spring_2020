#include "matrix.h"

Row::Row(const int col)
{
    columns = col;
    a = new int[columns];
    for(int i=0;i<columns;i++)
    a[i]=0;
}
Row::~Row()
{
    //std::cout<<"destructbeg"<<std::endl;
    columns=0;
    //std::cout<<"destructend"<<std::endl;
}
int& Row::operator[](int ncolumn) const
{
    if (ncolumn>columns)
        throw std::out_of_range("What a shame");
    return a[ncolumn];
}
void Row::operator*=(int k)
{
    for (int i=0;i<columns;i++)
    a[i]*=k;
}
bool Row::operator==(const Row rot)
{
    for (int i=0;i<columns;i++)
    {
       if (a[i]!=rot.a[i])
            return false;
    }
    return true;
}
bool Row::operator!=(const Row rot)
{
    return !(*this==rot);
}

Matrix::Matrix(int ra,int col)
{
    rows=ra;
    columns=col;
    raw = new int[rows*columns];
    for(int i=0;i<rows*columns;i++)
    raw[i]=0;
}
Matrix::~Matrix()
{
    //std::cout<<"destructmatbeg"<<std::endl;
    delete[] raw;
    rows=0;
    columns=0;
    //std::cout<<"destructmatend"<<std::endl;
}
Row Matrix::operator[](int nrow) const
{
    Row strok(columns);
    if (nrow>=rows)
        throw std::out_of_range("What a shame");
    for (int i=0;i<columns;i++)
        strok.a=raw+nrow*columns;
    return strok;
}
void Matrix::operator*=(int k)
{
    for (int i=0;i<rows*columns;i++)
        raw[i]*=k;
}
int Matrix::getrows() const
{
    return rows;
}
int Matrix::getcolumns() const
{
    return columns;
}
bool Matrix::operator==(const Matrix& Mat)
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
bool Matrix::operator!=(const Matrix& Mat)
{
    return !(*this==Mat);
}