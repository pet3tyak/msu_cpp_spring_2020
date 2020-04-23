#include <iterator>

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    T* ptr_;

public:
    Iterator(T* ptr)
        : ptr_(ptr)
    {
    }

    operator T*()
    {
        return ptr_;
    }

    T& operator*()
    {
        return *ptr_;
    }

    T& operator[](std::ptrdiff_t n)
    {
        return *(ptr_ + n);
    }

    Iterator<T>& operator++()
    {
        ptr_++;
        return *this;
    }

    Iterator<T>& operator--()
    {
        ptr_--;
        return *this;
    }

    Iterator<T>& operator+=(std::ptrdiff_t n)
    {
        ptr_ += n;
        return *this;
    }

    Iterator<T>& operator-=(std::ptrdiff_t n)
    {
        ptr_ -= n;
        return *this;
    }

    Iterator<T> operator+(std::ptrdiff_t n) const
    {
        return Iterator<T>(ptr_ + n);
    }

    Iterator<T> operator-(std::ptrdiff_t n) const
    {
        return Iterator<T>(ptr_ - n);
    }

    std::ptrdiff_t operator-(const Iterator<T>& it) const
    {
        return ptr_ - it.ptr_;
    }

    bool operator==(const Iterator<T>& it) const
    {
        return ptr_ == it.ptr_;
    }
    bool operator!=(const Iterator<T>& it) const
    {
        return ptr_ != it.ptr_;
    }
};
