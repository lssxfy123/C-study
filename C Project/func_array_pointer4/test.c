// ָ�������ָ����ָ������

#include <stdio.h>

void average(float* p, int n);
void search(float (*p)[4], int n);
void search1(float** p, int n);
void search2(float (*p)[3]);

int main(int argc, char* argv[])
{
    int i;
    float* p[3];  // ����ָ��
    float score[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};
    float a[3] = {1, 2, 3};

    for (i = 0; i != 3; ++i)
    {
        p[i] = score[i];
    }
    average(*score, 12);
    search(score, 2);
    // search1(score, 2);  // ����������ֵ����C�����б��벻������⣬���޷�����
    search1(p, 2);

    search2(&a);  // ������a���ɱ����������ַ����ָ�������ָ��
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
        // p��һ��ָ�������ָ�뼴����ָ��
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
