// Copyright 2017.���|�|
// author�����|�|
// ����ָ����Ϊ�β�
#include <stdio.h>

int max(int, int);
int min(int, int);
void processor(int, int, int (*p)(int, int));  // ����ָ����Ϊ�β�

int main(int argc, char* argv[])
{
    int a = 6;
    int b = 7;

    printf("max = ");
    processor(a, b, max);  // ��������һ������ָ��

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
