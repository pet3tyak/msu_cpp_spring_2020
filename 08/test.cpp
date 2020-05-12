#include "pool.h"
#include <iostream>


struct A
{
    int data = 3;
};
void foo(const A& a)
{
    std::cout << a.data << std::endl;
}

int main(int argc, char* argv[])
{
    ThreadPool pool(8);

    auto task1 = pool.exec(foo, A());
    task1.get();

    auto task2 = pool.exec([]()
        {
            return 1;
        });
    std::cout << task2.get() << std::endl;

    std::cout << '\n';

    for (int i = 0; i <= 20; ++i)
    {
        std::cout << pool.exec([i]()
                             {
                                 return i;
                             })
                         .get()
                  << '\n';
    }
}

