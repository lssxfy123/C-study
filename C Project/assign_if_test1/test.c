// Copyright 2017.���|�|
// author�����|�|
// ��ֵ���ʽ��Ϊ�ж�����
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a;
    int b = 1;

    int c;
    int d = 0;

    if (a = b)  // true a = b = 1
    {
        printf("����Ϊ��\n");
    }
    else {
        printf("����Ϊ��\n");
    }

    if (c = d)  // false c = 0
    {
        printf("����Ϊ��\n");
    }
    else {
        printf("����Ϊ��\n");
    }
    return 0;
}
