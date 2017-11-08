// Copyright 2017.���|�|
// author�����|�|
// vector��string���ݸ��ɵ�C API
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

// ����C API��ʼ��vector
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
    vector<double> vec(max_number);  // ��Ҫ����vector�Ĵ�С

    // ����vector��C API����
    // ע�⣺C API����Ĵ�С����С�ڻ����vector��size
    vec.resize(FillVector(&vec[0], 5));
    PrintElements(vec, "C API Fill vector: ");
    cout << endl;

    vector<char> vec1(max_number);
    size_t chars = FillString(&vec1[0], vec1.size());
    string str(vec1.begin(), vec1.begin() + chars);
    cout << "str = " << str << endl;
    return 0;
}
