// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ¶ÑÄÚ´æ·ÖÅä
#include <malloc.h>
#include <stdio.h>

int* func();

int main(int argc, char* argv[])
{
    int j;
    int* p = NULL;

    p = func();

    for (j = 0; j != 3; ++j)
    {
        printf("%d\n", p[j]);
    }

    free(p);
    p = NULL;
    return 0;
}

int* func()
{
    int i = 0;
    int* p = (int*)malloc(3 * sizeof(int));

    for (i = 0; i != 3; ++i)
    {
        p[i] = i + 3;
    }
    return p;
}
