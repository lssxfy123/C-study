// Copyright 2017.刘珅珅
// author：刘珅珅
// 无符号数和有符号数
#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int k = 1;
    int m = -9;

    short int m1 = -1;
    unsigned short int n = 65535;

    int s = 0;

    // k为无符号数，m+8的结果-1的补码当成无符号数处理
    k = m + 8;
    printf("%u\n", k);  // 4294967295

    // m1为有符号数，n-9的结果65526的补码当成有符号数处理
    m1 = n - 9;
    printf("%d\n", m1);  // -10

    // 发生溢出，得到的是-2的补码
    // 1111 1111 1111 1111 1111 1111 1111 1111 +
    // 1111 1111 1111 1111 1111 1111 1111 1111
    // = 1111 1111 1111 1111 1111 1111 1111 1110
    s = k + k;
    printf("%d\n", s);  // -2

    return 0;
}

