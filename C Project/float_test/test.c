// Copyright 2017.刘珅珅
// author：刘珅珅
// 浮点数的输出精度
#include <stdio.h>

int main(int argc, char* argv[])
{
    float a = 12345.789e5;
    float b = a + 20;
    float e = 2.456f * 2.34f;

    printf("%f\n", a);
    printf("%f\n", b);
    printf("%f\n", e);
    return 0;
}
