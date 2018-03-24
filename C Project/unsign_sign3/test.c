// Copyright 2017.���|�|
// author�����|�|
// �޷��������з�����
#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned char b = 54;
    unsigned char c = 254;

    char m = 2;
    char n = 65;

    char x = -102;
    char y = -126;

    m = m >> 1;  // 1

    // n : 0100 0001
    // ����1λ��1000 0010
    n = n << 1;
    printf("n = %d\n", n);  // -126

    // ����1λ��0000 0100
    n = n << 1;
    printf("n = %d\n", n);  // 4

    x = x >> 1;
    printf("x = %d\n", x);  // -51

    x = x >> 10;  // -1
    printf("x = %d\n", x);
    
    y = y << 1;
    printf("y = %d\n", y);

    b = b << 1;

    // 254:1111 1110
    // ����1λ��ɣ�1111 1100
    c = c << 1;  // 252

    printf("m = %d\n", m);

    printf("b = %u\n", b);
    printf("c = %u\n", c);
    return 0;
}
