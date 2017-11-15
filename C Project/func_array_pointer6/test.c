// 字符串与字符指针

#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    char a[] = "I am a boy";
    char b[20];
    char c[20];

    for (i = 0; a[i] != '\0'; ++i)
    {
        b[i] = a[i];
    }
    b[i] = '\0';  // 字符串结束标志

    for (i = 0; *(a + i) != '\0'; ++i)
    {
        *(c + i) = *(a + i);
    }
    *(c + i) = '\0';

    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);
    return 0;
}
