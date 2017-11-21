// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// getchar/putchar
#include <stdio.h>

int main(int argc, char* argv[])
{
    char a = 'B';
    char b = 'O';
    char c = 'Y';

    char a1 = getchar();
    char b1 = getchar();
    char c1 = getchar();

    putchar(a);
    putchar(b);
    putchar(c);
    putchar('\n');

    putchar(a1);
    putchar(b1);
    putchar(c1);
    putchar('\n');
    return 0;
}
