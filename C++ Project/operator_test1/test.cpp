// Copyright 2017.刘珅珅
// author：刘珅珅
// 运算符重载
#include <iostream>
using std::cout;
using std::endl;

#include "base.h"

int main(int argc, char* argv[])
{
    Base b;
    
    b->func();  // 可以这样调用，相当于b.operator ->()->func()
    return 0;
}
