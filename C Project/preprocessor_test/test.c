// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ºê¶¨Òå
#include <stdio.h>

#define S 3 + 2

#define SQUARE(a) ((a) * (a))

#define PR printf
#define NL "\n"
#define D "%d"
#define D1 D NL
#define D2 D D NL

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 4;
    int c = 0;

    a = S * 3;
    c = SQUARE(b++);

    printf("%d\n", a);
    printf("%d\n", c);
    printf("%d\n", b);

    PR(D1, a);
    PR(D2,a, b);
    return 0;
}
