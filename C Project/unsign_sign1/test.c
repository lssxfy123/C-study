// Copyright 2017.���|�|
// author�����|�|
// �޷��������з����������
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = -1;
    unsigned int b = 0;

    unsigned int g = 0;
    int h = 0;

    int c = 2147483647;

    // �����������d = 2147483647
    // -2147483648�Ĳ���Ϊ1000 0000 0000 0000 0000 0000 0000 0000
    // -1�Ĳ���Ϊ1111 1111 1111 1111 1111 1111 1111 1111
    // ��Ӻ����Ϊ0111 1111 1111 1111 1111 1111 1111 1111
    // Ϊ2147483647
    int d = -2147483648 - 1;

    int e = 2147483647;
    unsigned int f = 2147383648;



    if (a < b)
    {
        printf("a < b\n");
    }
    else if (a == b)
    {
        printf("a = b \n");
    }
    else
    {
        printf("a > b \n");
    }

    if (h < (g - 1))
    {
        printf("%u\n", (g - 1));
        printf("h < (g - 1)\n");
    }

    if (c < d)
    {
        printf("c < d\n");
    }
    else if (c == d)
    {
        printf("d = %d\n", d);
        printf("c = d \n");
    }
    else
    {
        printf("c > d \n");
    }

    return 0;
}



