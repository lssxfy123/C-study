// Copyright 2017.���|�|
// author�����|�|
// �޷��������з�����
#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned int k = 1;
    int m = -9;

    short int m1 = -1;
    unsigned short int n = 65535;

    int s = 0;

    // kΪ�޷�������m+8�Ľ��-1�Ĳ��뵱���޷���������
    k = m + 8;
    printf("%u\n", k);  // 4294967295

    // m1Ϊ�з�������n-9�Ľ��65526�Ĳ��뵱���з���������
    m1 = n - 9;
    printf("%d\n", m1);  // -10

    // ����������õ�����-2�Ĳ���
    // 1111 1111 1111 1111 1111 1111 1111 1111 +
    // 1111 1111 1111 1111 1111 1111 1111 1111
    // = 1111 1111 1111 1111 1111 1111 1111 1110
    s = k + k;
    printf("%d\n", s);  // -2

    return 0;
}
