// Copyright 2017.刘珅珅
// author：刘珅珅
// 不同头文件定义相同的类引发的错误
#include <iostream>
using std::cout;
using std::endl;

#include "a.h"
//#include "b.h"

int main(int argc, char* argv[])
{
    return 0;
}
