// Copyright 2017.���|�|
// author�����|�|
// ������Ϊ�β�
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

    func(b);  // ���������������ܿ���������
	printf("%d\n", b[7]);  // ��������������δ֪
    printf("%x\n", a);
    printf("%x\n", a[0]);
    printf("%d\n", a[0][0]);
    return 0;
}

void func(int a[])
{
    printf("%d\n", a[9]);
}
