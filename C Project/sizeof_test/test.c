// Copyright 2017.���|�|
// author�����|�|
// sizeof����������������ڴ��С
#include <stdio.h>

void func(int b[10]);

int main(int argc, char* argv[])
{
    char a[50];
    int b[10];
    char c[] = "abcde";

    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(short));

    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));  // 6

    func(b);

    return 0;
}

void func(int b[10])
{
    printf("%d\n", sizeof(b));  // 4��bΪָ��
}
