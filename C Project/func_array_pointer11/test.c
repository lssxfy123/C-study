// 指针与函数：指针函数

#include <malloc.h>
#include <stdio.h>

int* func();
int* func1();

int main(int argc, char* argv[])
{
    int* p = NULL;

    p = func();
    printf("%d\n", *p);

    p = func1();

    printf("%d, %d\n", *p, *(p + 1));
    free(p);

    return 0;
}

int* func()
{
    int a = 20;
    return &a;
}

int* func1()
{
    int* p = (int*)malloc(2 * sizeof(int));
    p[0] = 2;
    p[1] = 3;
    return p;
}
