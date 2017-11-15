// 指向数组的指针与指针数组

#include <stdio.h>

void average(float* p, int n);
void search(float (*p)[4], int n);
void search1(float** p, int n);
void search2(float (*p)[3]);

int main(int argc, char* argv[])
{
    int i;
    float* p[3];  // 二重指针
    float score[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};
    float a[3] = {1, 2, 3};

    for (i = 0; i != 3; ++i)
    {
        p[i] = score[i];
    }
    average(*score, 12);
    search(score, 2);
    // search1(score, 2);  // 不能这样赋值，在C语言中编译不会出问题，但无法运行
    search1(p, 2);

    search2(&a);  // 将数组a看成变量，将其地址赋给指向数组的指针
    return 0;
}

void average(float* p, int n)
{
    float* p_end;
    float sum = 0;
    float aver;

    p_end = p + n - 1;
    for (; p <= p_end; ++p)
    {
        sum = sum + (*p);
    }

    aver = sum / n;

    printf("average = %5.2f\n", aver);
}

void search(float (*p)[4], int n)
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        printf("%5.2f ", *(*(p + n) + i));
    }
    printf("\n");
}

void search2(float (*p)[3])
{
    int i = 0;
    for (i = 0; i < 3; ++i)
    {
        // p是一个指向数组的指针即数组指针
        printf("%5.2f ", (*p)[i]);
    }
    printf("\n");
}

void search1(float** p, int n)
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        printf("%5.2f ", *(*(p + n) + i));
    }
    printf("\n");
}
