// Copyright 2017.���|�|
// author�����|�|
// �޷��������з�����
#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int i = 1;
    int j = -9;

    short int m = -1;
    unsigned short int n = 65535;

    int k = 0;

    i = j + 8;  // j�������޷���������

    printf("%u\n", i);  // 4294967295������-9�Ĳ���ת��Ϊ�޷�������ֵ�ټ���8�õ���ֵ

    m = n - 9;
    printf("%d\n", m);  // -10����n�����з�����������ֵΪ-1

    k = i * j;
    printf("%d\n", k);

    return 0;
}
