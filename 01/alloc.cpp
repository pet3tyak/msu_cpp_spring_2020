#include <cstddef>
#include "all.h"

using namespace std;

allocat::allocat()
{
    maxsize=0;
    size=0;
}

allocat::~allocat()
{
    if (maxsize) 
    {
        delete[] val;
        val=NULL;
    }
}

void allocat::makeAllocator(size_t max)
{
    if (val) delete[] val;
    maxsize=max;
    size=0;
    val=new char[maxsize/sizeof(char)];
}

char* allocat::alloc(size_t siz)
{
    if (siz+size>maxsize) return nullptr;
    char* pnt=val+size/sizeof(char);
    size+=siz;
    return pnt;
}

void allocat::reset()
{
    size=0;
}
