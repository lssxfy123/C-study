// Copyright 2017.���|�|
// author�����|�|
// ���б���������
#include <iostream>

int main(int argc, char* argv[])
{
    int* p = new int[3];
    int& a = *p;

    std::cout << p << std::endl;
    std::cout << &a << std::endl;

    delete [] p;  // ��Ч��delete [] &a;
    p = NULL;
    return 0;
}
