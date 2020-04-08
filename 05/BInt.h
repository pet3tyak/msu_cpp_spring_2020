#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstddef>

class BigInt{
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
    const BigInt operator-() const;
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
    const BigInt operator+(const BigInt& b) const;
    const BigInt operator+(const int b) const;
    const BigInt operator-(const BigInt &b) const;
    const BigInt operator-(const int b) const;
    const BigInt abs() const;
};
