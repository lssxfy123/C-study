// Copyright 2017.刘珅珅
// author：刘珅珅
// 浮点数的输出精度
#include <stdio.h>

int main(int argc, char* argv[])
{
    float a = 12345.789e5;
    float b = a + 20;
    float e = 2.456f * 2.34f;

    double x = 4 / 512;
    double x1 = 4 / 512.0;
    double x2 = 4.0 / 512;
    double x3 = 4.0 / 512.0;

    printf("%f\n", a);
    printf("%f\n", b);
    printf("%f\n", e);

    printf("%f\n", x);
    printf("%f\n", x1);
    printf("%f\n", x2);
    printf("%f\n", x3);
    printf("%f\n", (float)3 / 4);
    return 0;
}
