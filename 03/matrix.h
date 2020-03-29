#include <stdexcept>
#include <cstddef>
#include <iostream>


class Matrix
{
    int* raw;
    size_t columns;
    size_t rows;
public:
    class Row
    {
        int* a;
        size_t columns;
    public:
        Row(const size_t col);
        Row(const size_t col, int* val);
        ~Row();
        const int& operator[](int ncolumn) const;
        int& operator[](int ncolumn);
    };
    Matrix(const size_t ra,const size_t col);
    ~Matrix();
    const Row operator[](int nrow) const;
    Row operator[](int nrow);
    Matrix& operator*=(int k);
    int getrows() const;
    int getcolumns() const;
    bool operator==(const Matrix& Mat) const;
    bool operator!=(const Matrix& Mat) const;
};
