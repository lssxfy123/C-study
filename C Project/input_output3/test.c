// Copyright 2017.刘珅珅
// author：刘珅珅
// 浮点数的输出
#include <stdio.h>

int main(int argc, char* argv[])
{
    int number = 9;
    float* f_ptr = &number;
    int a = 1234567890;


    printf("number = %d\n", number);
    printf("*f_ptr = %f\n", *f_ptr);

    *f_ptr = 1234567890;

    printf("number = %d\n", number);
    printf("a = %d \n", a);
    printf("*f_ptr = %f\n", *f_ptr);

    *f_ptr = 12.34;

    printf("number = %x\n", number);
    printf("*f_ptr = %f\n", *f_ptr);


    //// 下面这种写法会报出内存错误
    //// 原因double型指针指向的地址
    //// 应该为8个字节，而实际指向的
    //// 是4个字节
    //double* d_ptr = &number;
    //*d_ptr = 9.8;

    // printf("%d\n", number);
    return 0;
}
