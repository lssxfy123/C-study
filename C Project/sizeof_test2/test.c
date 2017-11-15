// 结构体的大小

#include <stdio.h>

struct A
{
    char i;
    double a;
};

struct C
{
    double a;
    char i;
};

struct B
{
    char c1;
    struct C c2;
    char c3;

};

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;

    a = sizeof(struct A);
    b = sizeof(struct B);
    c = sizeof(struct C);

    printf("%d\n", a);  // 16
    printf("%d\n", b);  // 32
    printf("%d\n", c);  // 16
    return 0;
}
