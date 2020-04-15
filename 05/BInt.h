#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstddef>

class BigInt{
    static const int MAX_CELL=1000000000;
    int* head;
    bool sign;
    int size;
public:
    BigInt();
    BigInt(const int val);
    BigInt(const BigInt& val);
    ~BigInt();
    BigInt &operator=(int val);
    BigInt &operator=(const BigInt &b);
    friend std::ostream &operator<<(std::ostream &cc, const BigInt& val);
    BigInt operator-() const;
    bool operator==(const BigInt& val) const;
    bool operator==(const int val) const;
    bool operator>(const BigInt& val) const;
    bool operator>(const int val) const;
    bool operator<(const BigInt& val) const;
    bool operator<(const int val) const;
    bool operator<=(const BigInt& val) const;
    bool operator<=(const int val) const;
    bool operator>=(const BigInt& val) const;
    bool operator>=(const int val) const;
    BigInt operator+(const BigInt& b) const;
    BigInt operator+(const int b) const;
    BigInt operator-(const BigInt &b) const;
    BigInt operator-(const int b) const;
    BigInt abs() const;
    bool ChangeMem(int size,bool isfree);
};
