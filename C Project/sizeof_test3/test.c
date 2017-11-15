// 结构体的大小

#include <stdio.h>

struct A
{
    double a;
    char i[11];
    int k;
};

struct C
{
    char i[11];
    double a;
    int k;
};

struct B
{
    char c1;
    struct A a1;
};
union S
{
    char c1;
    struct B b1;
};

union S1
{
    char c1;
    int a[10];
    double b;
};

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int s = 0;
    int s1 = 0;

    a = sizeof(struct A);
    b = sizeof(struct B);
    c = sizeof(struct C);
    s = sizeof(union S);
    s1 = sizeof(union S1);

    printf("%d\n", a);  // 24
    printf("%d\n", b);  // 32
    printf("%d\n", c);  // 32
    printf("%d\n", s);  // 32
    printf("%d\n", s1);  // 40
    return 0;
}
