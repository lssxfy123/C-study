// Copyright 2017.刘珅珅
// author：刘珅珅
// 指针与数组
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    int j;
    int a[5];
    int* p = a;
    int b[5] = {0};

    for (i = 0; i != 5; ++i)
    {
        a[i] = i + 1;
    }

    for (j = 0; j != 5; ++j)
    {
        printf("%d\n", a[j]);
        printf("%d\n", *(p + j));
        printf("%d\n", *(a + j));
    }

    *a = 10;
    *(a + 1) = 11;

    for (j = 0; j != 5; ++j)
    {
        printf("%d\n", a[j]);
        printf("%d\n", *(p + j));
        printf("%d\n", *(a + j));
    }

    for (j = 0; j != 5; ++j)
    {
        printf("%d\n", b[j]);
    }

    // a++;  // error，a为指针常量
    return 0;
}
