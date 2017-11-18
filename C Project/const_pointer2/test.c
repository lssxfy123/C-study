// Copyright 2017.刘珅珅
// author：刘珅珅
// const指针做函数的形参
#include <stdio.h>

void func(const int* p)
{
    // *p = 4;  // error，不能修改p指向的对象

    printf("%d\n", *p);

    // 可以修改p指针本身
    // 不会影响到传入的实参
    p = NULL; 
}

int main(int argc, char* argv[])
{
    int a = 2;
    int* p = &a;

    func(p);
    printf("%d\n", *p);  // 2

    return 0;
}
