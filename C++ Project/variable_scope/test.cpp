// Copyright 2017.刘珅珅
// author：刘珅珅
// C++中的函数作用域
#include <iostream>
using namespace std;

int number = 1;
static int value = 2;

int main(int argc, char* argv[])
{
    extern int a;
    a = 1;  // 不用extern扩展，则error
    number = 0;
    value = 9;

    return 0;
}

int a = 0;

