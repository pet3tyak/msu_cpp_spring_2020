#include "BInt.h"

int main()
{
    BigInt a;
    BigInt b(10);
    BigInt c=20;
    BigInt d=b;
    BigInt e=-c;
    BigInt f;
    f=b;
    a=2000000000;
    std::cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<' '<<(a-a)<<' '<<(c-a)<<' '<<(a+c)<<' '<<-a<<' '<<(a>b);
    return 0;
}
