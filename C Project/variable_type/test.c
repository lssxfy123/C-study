// Copyright 2017.刘珅珅
// author：刘珅珅
// C语言内置类型的大小
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 0;
    short b = 1;
    long l = 234;
    long long ll = 456;
    float f = 23.4;
    double d = 45.6;
    char c = 'B';
    char str[] = "abcde";

    char* p = str;
    double* p1 = &d;

    if (str[5] == '\0')
    {
        printf("最后一个字符为结束符\n");
    }
    else
    {
        printf("最后一个字符不为结束符\n");
    }

    printf("int %d\n", sizeof(a));
    printf("char[] %d\n", sizeof(str));
    printf("pointer %d\n", sizeof(p));
    printf("char %d\n", sizeof(c));
    printf("short %d\n", sizeof(b));
    printf("long %d\n", sizeof(l));
    printf("long long %d\n", sizeof(ll));
    printf("float %d\n", sizeof(f));
    printf("double %d\n", sizeof(d));
    printf("pointer %d\n", sizeof(p1));

    return 0;
}
