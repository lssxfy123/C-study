// Copyright 2015.Áõ«|«|
// author£ºÁõ«|«|
// ¸¡µãÊı´æ´¢
#include <stdio.h>

int main(int argc, char* argv[])
{
    int number = 9;
    float* f_ptr = (float*)&number;
    int a = 1234567890;

    printf("number = %d\n", number);
    printf("*f_ptr = %f\n", *f_ptr);

    *f_ptr = 1234567890;

    printf("number = %d\n", number);
    printf("a = %d \n", a);
    printf("*f_ptr = %f\n", *f_ptr);

    float b = 1234567890;
    printf("b = %f\n", b);
    return 0;
}
