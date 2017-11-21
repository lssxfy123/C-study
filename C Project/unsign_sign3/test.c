// Copyright 2017.刘珅珅
// author：刘珅珅
// 无符号数与有符号数
#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int i = 1;
    int j = -9;

    short int m = -1;
    unsigned short int n = 65535;

    int k = 0;

    i = j + 8;  // j被当成无符号数处理

    printf("%u\n", i);  // 4294967295，这是-9的补码转换为无符号数的值再加上8得到的值

    m = n - 9;
    printf("%d\n", m);  // -10，将n当成有符号数处理，其值为-1

    k = i * j;
    printf("%d\n", k);

    return 0;
}
