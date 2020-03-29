#include <stdexcept>
#include <cstddef>
#include <iostream>


class Matrix
{
        int* raw;
        int columns;
        int rows;
    public:
        class Row
        {
            public:
                int* a;
                int columns;
                Row(const size_t col);
                Row(const size_t col, int* val);
                ~Row();
                const int& operator[](int ncolumn) const;
                int& operator[](int ncolumn);
                Row* operator*=(int k);
                bool operator==(const Row rot) const;
                bool operator!=(const Row rot) const;
        };
        Matrix(const size_t ra,const size_t col);
        ~Matrix();
        const Row operator[](int nrow) const;
        Row operator[](int nrow);
        Matrix* operator*=(int k);
        int getrows() const;
        int getcolumns() const;
        bool operator==(const Matrix& Mat) const;
        bool operator!=(const Matrix& Mat) const;
};
