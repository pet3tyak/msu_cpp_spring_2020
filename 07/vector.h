#include "allocator.h"
#include "iterator.h"
#include <iostream>
#include <iterator>
#include <memory>

template <class T, class Alloc = Allocator<T> >
class Vector
{
    Alloc alloc;
    size_t size_;
    T* data;
private:
    Iterator<T> start, finish;

public:
    Vector()
        : size_(0)
        , data(alloc.allocate(size_))
        , start(data)
        , finish(data)
    {
	}

    T& operator[](std::ptrdiff_t i)
    {
        return data[i];
    }

    void push_back(const T& value)
    {
        if (size() >= size_)
        {
            reserve(size_ * 2 + 1);
        }
        alloc.construct(finish, value);
        ++finish;
    }

    void pop_back()
    {
        if (size() > 0)
        {
            --finish;
            alloc.destroy(finish);
        }
    }

    bool empty() const
    {
        return start == finish;
    }

    size_t size() const
    {
        return finish - start;
    }

    size_t capacity() const
    {
        return size_;
    }

    void clear()
    {
        resize(0);
    }

    Iterator<T> begin()
    {
        return start;
    }

    Iterator<T> end()
    {
        return finish;
    }

    std::reverse_iterator<Iterator<T> > rbegin()
    {
        return std::reverse_iterator<Iterator<T> >(finish);
    }

    std::reverse_iterator<Iterator<T> > rend()
    {
        return std::reverse_iterator<Iterator<T> >(start);
    }

    void resize(size_t new_size)
    {
        if (size_ < new_size)
        {
            reserve(new_size);
        }

        Iterator<T> prev = finish;
        finish = start + new_size;

        while (prev > finish)
        {
            --prev;
            alloc.destroy(prev);
        }
        while (prev < finish)
        {
            alloc.construct(prev, T());
            ++prev;
        }
    }

    void reserve(size_t new_size)
    {
        if (new_size > size_)
        {
            size_t sz = size();
            T* mem = alloc.allocate(new_size);
            for (size_t i = 0; i < sz; ++i)
            {
                alloc.construct(mem + i, std::move(data[i]));
                alloc.destroy(data + i);
            }
            alloc.deallocate(data, size_);
            size_ = new_size;
            data = mem;
            start = Iterator<T>(data);
            finish = start + sz;
        }
    }

	~Vector()
    {
        for (T* ptr = data; ptr < data + size(); ++ptr)
        {
            alloc.destroy(ptr);
        }
        alloc.deallocate(data, size_);
    }
};
