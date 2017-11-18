// Copyright 2017.刘珅珅
// author：刘珅珅
// 赋值表达式作为判断条件
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a;
    int b = 1;

    int c;
    int d = 0;

    if (a = b)  // true a = b = 1
    {
        printf("条件为真\n");
    }
    else {
        printf("条件为假\n");
    }

    if (c = d)  // false c = 0
    {
        printf("条件为真\n");
    }
    else {
        printf("条件为假\n");
    }
    return 0;
}
