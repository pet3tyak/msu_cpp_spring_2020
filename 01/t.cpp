#include "all.h"
//#include <cstddef>
#include <cassert>

void test1()
{
    allocat all;
    all.makeAllocator(20*sizeof(char));
    assert(nullptr != all.alloc(20*sizeof(char)));
    assert(nullptr == all.alloc(1*sizeof(char)));
    all.reset();
    assert(nullptr != all.alloc(10*sizeof(char)));
    assert(nullptr != all.alloc(10*sizeof(char)));
    assert(nullptr == all.alloc(1*sizeof(char)));
}

void test2()
{
    allocat all;
    all.makeAllocator(10*sizeof(char));
    assert(nullptr == all.alloc(11*sizeof(char)));
    assert(nullptr != all.alloc(5*sizeof(char)));
    assert(nullptr != all.alloc(5*sizeof(char)));
    assert(nullptr == all.alloc(1*sizeof(char)));
}

int main()
{
    test1();
    test2();
    return 0;
}
