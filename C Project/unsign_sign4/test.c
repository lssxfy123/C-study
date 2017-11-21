// Copyright 2017.刘珅珅
// author：刘珅珅
// 无符号数与有符号数
#include <stdio.h>

int main(int argc, char* argv[])
{
    char a = -2;
    unsigned char b = 254;

    int m = -1;
    int n = -2;
    unsigned int k = m + n;

    unsigned int x = 1;
    unsigned int y = 2;
    int z = x + y;
    a = a >> 1;
    b = b >> 1;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("k = %u\n", k);
    printf("z = %u\n", z);

    return 0;
}
