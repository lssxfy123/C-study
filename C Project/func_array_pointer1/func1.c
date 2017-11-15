#include <stdio.h>

int n = 10;
static int m = 15;

void func1(int k)
{
    ++k;
    printf("k = %d\n", k);
    printf("m = %d\n", m);
}
