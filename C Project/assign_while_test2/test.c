// Copyright 2017.刘珅珅
// author：刘珅珅
// 赋值表达式作为判断条件
#include <stdio.h>

int main(int argc, char* argv[])
{
    char str1[10] = {0};
    char str2[] = "abcde";

    char* p1= str1;
    char* p2 = str2;


    // 不能直接使用数组名，因其为指针常量，不能进行++运算
    // p2的最后一位为'/0'结束符，*p2就为0，对应的*p1 = 0
    // while循环结束
    while (*p1++ = *p2++) 
    {
    }

    printf("%s\n", str1);
    return 0;
}
