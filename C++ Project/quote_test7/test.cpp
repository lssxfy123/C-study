// Copyright 2017.刘珅珅
// author：刘珅珅
// 堆中变量的引用
#include <iostream>

int main(int argc, char* argv[])
{
    int* p = new int[3];
    int& a = *p;

    std::cout << p << std::endl;
    std::cout << &a << std::endl;

    delete [] p;  // 等效于delete [] &a;
    p = NULL;
    return 0;
}
