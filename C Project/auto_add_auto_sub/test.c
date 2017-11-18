// Copyright 2017.刘珅珅
// author：刘珅珅
// 自增自减运算符
#include <stdio.h>
int main(int argc, char* argv[])
{
    int a = 10;
    int b = 0;
    int c = 0;
    int d = 0;

    int i = 10;
    int j = 2;
    int k = (i++) + j;

    b = a++;
    c = ++a;
    d = 10 * a++;

    printf("%d, %d, %d\n", b, c, d);  // 10, 12 120
    printf("%d\n", k);  // 12
    return 0;
}
