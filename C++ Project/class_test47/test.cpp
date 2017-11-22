// Copyright 2017.刘珅珅
// author：刘珅珅
// 静态函数访问其他类的非静态成员
#include <iostream>
using std::cout;
using std::endl;

#include "a.h"
#include "b.h"

int main(int argc, char* argv)
{
    B b;
    A::func(b);
    return 0;
}
