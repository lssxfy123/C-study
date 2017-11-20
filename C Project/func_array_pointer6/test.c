// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ×Ö·û´®Óë×Ö·ûÖ¸Õë
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
    b[i] = '\0';  // ×Ö·û´®½áÊø±êÖ¾

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
