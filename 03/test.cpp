/*int main()
{
    const size_t rows = 5;
    const size_t cols = 3;
    std::cout<<1<<std::endl;
    Matrix m(rows, cols);
    std::cout<<1<<std::endl;
    assert(m.getrows() == 5);
    assert(m.getcolumns() == 3);
    std::cout<<1<<std::endl;
    m[1][2] = 5; // строка 1, колонка 2
    double x = m[4][1];
    //std::cout<<x<<std::endl;
    std::cout<<1<<std::endl;
    m *= 3; // умножение на число
    std::cout<<1<<std::endl;
    Matrix m1(rows, cols);
    std::cout<<1<<std::endl;
    if (m1 == m)
    {
    }
    std::cout<<1<<std::endl;
}*/


#include "matrix.h"
#include <iostream>
#include <cassert>

void test1() {
    const size_t rows = 5;
    const size_t cols = 3;

    Matrix m(rows, cols);

    assert(m.getrows() == 5);
    assert(m.getcolumns() == 3);

    m[1][2] = 5; 
    double x = m[1][2];
    assert(x == 5);
}
void test2() {
    const size_t rows = 4;
    const size_t cols = 4;
    Matrix m1(rows, cols);
    Matrix m2(rows, cols);
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            m1[i][j] = i * j;
            m2[i][j] = m1[i][j];
        }
    }
    assert(m1 == m2);
    m1 *= 3;
    assert(m1 != m2);
    assert(m1[2][2] == 12);
}

int main() {
    test1();
    test2();
    //const Matrix m(4,5);
    //m[1][1]=1;
    return 0;
}
