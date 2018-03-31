// Copyright 2017.刘珅珅
// author：刘珅珅
// C语言数组的测试
#include <stdio.h>
int c[5];

int main(int argc, char* argv[])
{
    int a[10][15][20];
    int i;
    int j;
    int k;
    int m;

    int b[5];

    for (k = 0; k < 20; ++k)
    {
        for (j = 0; j < 15; ++j)
        {
            for (i = 0; i < 10; ++i)
            {
                a[i][j][k] = i + j + k;
            }
        }
    }

    for (m = 0; m != 10; ++m)
    {
        printf("%d\n", a[m][0][0]);
    }

    for (m = 0; m != 5; ++m)
    {
        // 随机数
        printf("%d\n", b[m]);
    }

    for (m = 0; m != 5; ++m)
    {
        // 全局变量：初始化为0
        printf("%d\n", c[m]);
    }

    // 输出为地址
    printf("%x\n", a[0]);
    printf("%x\n", a[0][1]);

    return 0;
}
