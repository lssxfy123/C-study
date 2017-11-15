// 堆内存分配

#include <malloc.h>
#include <stdio.h>

int** func();

int main(int argc, char* argv[])
{
    int i;
    int** p = NULL;
    p = func();

    for (i = 0; i != 4; ++i)
    {
        printf("%d, ", p[0][i]);
    }

    printf("\n");

    for (i = 0; i != 5; ++i)
    {
        printf("%d, ", p[1][i]);
    }

    printf("\n");

    for (i = 0; i != 6; ++i)
    {
        printf("%d, ", p[2][i]);
    }

    printf("\n");

    free(p[0]);
    p[0] = NULL;

    free(p[1]);
    p[1] = NULL;

    free(p[2]);
    p[2] = NULL;

    free(p);
    p = NULL;

    return 0;
}

int** func()
{
    int i;
    int** p = (int**)malloc(3 * sizeof(int*));
    int* p1 = (int*)malloc(4 * sizeof(int));
    int* p2 = (int*)malloc(5 * sizeof(int));
    int* p3 = (int*)malloc(6 * sizeof(int));

    for (i = 0; i != 4; ++i)
    {
        p1[i] = i + 1;
    }

    for (i = 0; i != 5; ++i)
    {
        p2[i] = i + 2;
    }

    for (i = 0; i != 6; ++i)
    {
        p3[i] = i + 3;
    }

    p[0] = p1;
    p[1] = p2;
    p[2] = p3;

    //free(p1);  // 不能释放内存，否则，二重指针指向的是未知的地址
    //free(p2);
    //free(p3);

    return p;
}
