#include <cstddef>

class allocat
{
    char *val;
    size_t maxsize;
    size_t size;
    public:
    allocat();
    ~allocat();
    void makeAllocator(size_t max);
    char* alloc(size_t siz);
    void reset();
};
