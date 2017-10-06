// Copyright 2017.刘珅珅
// author：刘珅珅
// constexpr函数
#include <iostream>
#include "../include/print.hpp"
using namespace std;

constexpr int new_size() { return 42; }

// 返回值不一定是常量表达式
constexpr int scale(int count)
{
    return new_size() * count;
}

int main(int argc, char* argv[])
{
    constexpr int foo = new_size();

    // ok，scale(2)的返回值为常量表达式
    int arr[scale(2)];
    int i = 2;

    // error，scale(i)不是常量表达式
    // int arr1[scale(i)];
    int k = scale(i);  // ok
    return 0;
}
