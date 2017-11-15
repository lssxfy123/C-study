#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 0;
    short b = 1;
    long int l = 234;
    long long ll = 456;
    float f = 23.4;
    double d = 45.6;
    char c = 'B';
    char str[] = "abcde";

    char* p = str;
    double* p1 = &d;

    if (str[5] == '\0')
    {
        printf("最后一个字符为结束符\n");
    }
    else
    {
        printf("最后一个字符不为结束符\n");
    }

    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(str));
    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(c));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(l));
    printf("%d\n", sizeof(ll));
    printf("%d\n", sizeof(f));
    printf("%d\n", sizeof(d));
    printf("%d\n", sizeof(p1));

    return 0;
}
