// Copyright 2017.刘珅珅
// author：刘珅珅
// 数组作为形参
#include <stdio.h>

void func(int a[]);

int main(int argc, char* argv[])
{
    int i;
    int j;
    int a[3][4];
    int b[5];

    for (i = 0; i != 3; ++i)
    {
        for (j = 0; j != 4; ++j)
        {
            a[i][j] = i + j;
        }
    }

    for (i = 0; i != 5; ++i)
    {
        b[i] = i;
    }

    func(b);  // 可以输出，看结果很可能有问题
	printf("%d\n", b[7]);  // 可以输出，看结果未知
    printf("%x\n", a);
    printf("%x\n", a[0]);
    printf("%d\n", a[0][0]);
    return 0;
}

void func(int a[])
{
    printf("%d\n", a[9]);
}
