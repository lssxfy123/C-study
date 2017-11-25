// Copyright 2017.刘珅珅
// author：刘珅珅
// 指针的引用作为形参
#include <iostream>

// v1为pi指针的引用，v2为pj指针的引用，修改引用等于修改实参本身。
void PtrSwap( int*& v1, int*& v2)
{
    int* tmp = v2;  // 中间变量为一个指针
    v2 = v1;
    v1 = tmp;
}

int main( int argc,  char *argv[] )
{
    int i = 10;
    int j = 20;
    int* pi = &i;
    int* pj = &j;

    std::cout << pi << std::endl;
    std::cout << pj << std::endl;

    // pi与pj本身发生了交换 
    PtrSwap( pi, pj );

    std::cout << pi << std::endl;
    std::cout << pj << std::endl;

    std::cout << *pi << std::endl; // 输出为：20
    std::cout << *pj << std::endl; // 输出为：10
    return 0;
}

