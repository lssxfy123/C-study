#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 10;
    int b = 0;
    int c = 0;
    int d = 0;

    int i = 10;
    int j = 2;
    int k = (i++) + j;

    b = a++;
    c = ++a;
    d = 10 * a++;

    printf("%d, %d, %d\n", b, c, d);
    printf("%d\n", k);
    return 0;
}
