// Copyright 2017.刘珅珅
// author：刘珅珅
// 指针的测试
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int n = 2;
    int* n_ptr = &n;

    cout << n_ptr << endl;  // 0116FA00
    cout << &n << endl;  // 0116fa00
    ++n_ptr;
    cout << n_ptr << endl;  // 0116FA04

    --n_ptr;
    cout << n_ptr << endl;  // 0116FA00

    int m = 5;
    int* m_ptr = &m;

    cout << m_ptr << endl;  // 0116F9E8

    int k = m_ptr - n_ptr;

    // k为两个地址之间的(差值) / (整型的字节大小)
    cout << k << endl;  // -6

    // error，指针不能与浮点数+或-
    // m_ptr = m_ptr + 9.2;

    // error，指针不能相加
    // int x = m_ptr + n_ptr;

    void* v_ptr = &m;
    //++v_ptr;  // error，void指针不能进行算术运算
    return 0;
}
