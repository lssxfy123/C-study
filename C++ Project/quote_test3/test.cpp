// Copyright 2017.刘珅珅
// author：刘珅珅
// 指针形参与引用形参
#include <iostream>

void func1(int* p);
void func2(int& n);
// void func2(int b);  // 不能这样进行函数重载

int main(int argc, char* argv[])
{
    int* p = NULL;
    int a = 3;

    p = &a;

    std::cout << p << std::endl;
    func1(p);
    std::cout << p << std::endl;
    std::cout << a << std::endl;

    func2(a);

    return 0;
}

void func1(int* p)
{
    *p = 5;
    p = NULL;
}

void func2(int& n)
{
    n = 6;
}

//void func2(int b)
//{
//    b = 8;
//}
