// Copyright 2017.刘珅珅
// author：刘珅珅
// 二重指针
#include <stdio.h>

void func(float** p);
void func1(float** p);
void func2(float** p);

int main(int argc, char* argv[])
{
    int i;
    int j;
    float* p[3];
    float score[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};

    for (i = 0; i != 3; ++i)
    {
        p[i] = score[i];
    }
    func(p);
    func1(p);
    // func2(p);
    

    printf("%4.2f\n", score[0][0]);


    printf("\n");

    printf("%4.2f\n", p[1][0]);
    printf("%4.2f\n", p[0][0]);  // 调用了func1,则p[0]为NULL

    return 0;
}

void func(float** p)
{
    **p = 102;
}

void func1(float** p)
{
    *p = NULL;
}

void func2(float** p)
{
    p = NULL;
}
