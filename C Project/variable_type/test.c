// Copyright 2017.���|�|
// author�����|�|
// C�����������͵Ĵ�С
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
        printf("���һ���ַ�Ϊ������\n");
    }
    else
    {
        printf("���һ���ַ���Ϊ������\n");
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
