#include <iostream>
#include <fstream>
#include <cassert>
#include "mysort.h"

int main()
{
    size_t TrueCount = 8192000;
    std::ofstream ofile;
    uint64_t t;
    std::ifstream file;
    ofile.open("binary.dat", std::ios::binary);
    if (!ofile.is_open())
    {
        std::cout << "Can't open file\n";
        return 0;
    }
    
    for (uint64_t i = TrueCount; i > 0; i--)
        ofile.write((char*)&i, sizeof(uint64_t));
    ofile.close();
    
    try
    {
        mysort("binary.dat", "out.dat",8388608);
        
        file.open("out.dat", std::ios::binary);
        
        for (uint64_t i = 1; i <= TrueCount; ++i)
        {
            file.read((char*)&t, sizeof(uint64_t));
            assert(t == i);
        }
        file.close();
        std::cout << "Ok\n";
    }
    catch (const std::exception& err)
    {
        std::cout << err.what();
    }
    catch (...)
    {
        std::cout << "Error\n";
    }
    ofile.open("binary.dat", std::ios::binary);
    if (!ofile.is_open())
    {
        std::cout << "Can't open file\n";
        return 0;
    }
    
    for (uint64_t i = 0; i < TrueCount; i++)
        ofile.write((char*)&i, sizeof(uint64_t));
    ofile.close();
    
    try
    {
        mysort("binary.dat", "out.dat",8388608);
        
        file.open("out.dat", std::ios::binary);
        for (uint64_t i = 0; i < TrueCount; ++i)
        {
            file.read((char*)&t, sizeof(uint64_t));
            assert(t == i);
        }
        file.close();
        std::cout << "Ok\n";
    }
    catch (const std::exception& err)
    {
        std::cout << err.what();
    }
    catch (...)
    {
        std::cout << "Error\n";
    }
    
    std::remove("binary.dat");
    std::remove("out.dat");
    std::remove("tmp.bin");
}
