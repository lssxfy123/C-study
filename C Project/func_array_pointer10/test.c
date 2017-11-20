// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数指针作为形参
#include <stdio.h>

int max(int, int);
int min(int, int);
void processor(int, int, int (*p)(int, int));  // 函数指针作为形参

int main(int argc, char* argv[])
{
    int a = 6;
    int b = 7;

    printf("max = ");
    processor(a, b, max);  // 函数名是一个函数指针

    printf("min = ");
    processor(a, b, min);
    return 0;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void processor(int a, int b, int (*p)(int, int))
{
    int result = p(a, b);
    printf("%d\n", result);
}
