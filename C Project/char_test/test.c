#include <stdio.h>

int main(int argc, char* argv[])
{
    char a = 'a';
    char b = 'b';

    char c = 'a';
    char* c1 = "a";

    printf("%c %c\n", a, b);
    printf("%d %d\n", a, b);
    printf("%c %c\n", a - 32, b - 32);
    return 0;
}
