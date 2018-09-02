// Copyright 2018.刘珅珅
// author：刘珅珅
// 取模运算符
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // 一般情况下，取模运算符%的结果
    // 与被除数的符号相同
    cout << 7 % 4 << endl;  // 3
    cout << 7 % -4 << endl;  // 3
    cout << -7 % 4 << endl;  // -3
    cout << -7 % -4 << endl;  // -3

    // 有符号数与无符号数取模时
    // 将有符号数看成无符号数处理
    int a = -5;
    unsigned int b = 7;
    cout << (unsigned int)a << endl;
    cout << a % b << endl; // 6
    return 0;
}
