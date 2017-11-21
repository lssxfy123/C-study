// Copyright 2017.刘珅珅
// author：刘珅珅
// 结构体的大小计算
#include <stdio.h>

struct A
{
    char c;
    int i;
};

struct B
{
    char c1;
    struct A a1;
    char c2;
};

struct C
{
    int a;
    char i;
};

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;

    a = sizeof(struct A);
    b = sizeof(struct B);
    c = sizeof(struct C);

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}

