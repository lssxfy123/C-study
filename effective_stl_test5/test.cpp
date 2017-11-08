// Copyright 2017.刘珅珅
// author：刘珅珅
// vector和string传递给旧的C API
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

// 利用C API初始化vector
size_t FillVector(double* array_ptr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        array_ptr[i] = i + 0.1;
    }
    return size;
}

size_t FillString(char* array_ptr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        array_ptr[i] = 'a' + i;
    }
    return size;
}

int main(int argc, char* argv[])
{
    int max_number = 10;
    vector<double> vec(max_number);  // 需要分配vector的大小

    // 传递vector给C API函数
    // 注意：C API数组的大小必须小于或等于vector的size
    vec.resize(FillVector(&vec[0], 5));
    PrintElements(vec, "C API Fill vector: ");
    cout << endl;

    vector<char> vec1(max_number);
    size_t chars = FillString(&vec1[0], vec1.size());
    string str(vec1.begin(), vec1.begin() + chars);
    cout << "str = " << str << endl;
    return 0;
}
