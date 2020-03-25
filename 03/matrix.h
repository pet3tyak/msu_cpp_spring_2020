#include <stdexcept>
#include <cstddef>
#include <iostream>


class Row
{
    public:
        int* a;
        int columns;
        Row(const int col);
        ~Row();
        int& operator[](int ncolumn) const;
        void operator*=(int k);
        bool operator==(const Row rot);
        bool operator!=(const Row rot);
};

class Matrix
{
    public:
        int* raw;
        int columns;
        int rows;
        Matrix(int ra,int col);
        ~Matrix();
        Row operator[](int nrow) const;
        void operator*=(int k);
        int getrows() const;
        int getcolumns() const;
        bool operator==(const Matrix& Mat);
        bool operator!=(const Matrix& Mat);
};