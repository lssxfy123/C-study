// Copyright 2017.刘珅珅
// author：刘珅珅
// 浮点数运算精度控制
#include <stdio.h>

int main(int argc, char* argv[])
{
    double x = 4 / 512;
    double x1 = 4 / 512.0;
    double x2 = 4.0 / 512;
    double x3 = 4.0 / 512.0;

    printf("%f\n", x);
    printf("%f\n", x1);
    printf("%f\n", x2);
    printf("%f\n", x3);
    printf("%f\n", (float)3 / 4);
    return 0;
}
