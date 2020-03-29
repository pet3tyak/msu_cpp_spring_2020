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
        const int& operator[](size_t ncolumn) const;
        int& operator[](size_t ncolumn);
    };
    Matrix(const size_t ra,const size_t col);
    ~Matrix();
    const Row operator[](size_t nrow) const;
    Row operator[](size_t nrow);
    Matrix& operator*=(int k);
    int getrows() const;
    int getcolumns() const;
    bool operator==(const Matrix& Mat) const;
    bool operator!=(const Matrix& Mat) const;
};
