// Copyright 2017.���|�|
// author�����|�|
// 100!���
#include <malloc.h>
#include <math.h>
#include <stdio.h>

int factorial(int* a, int pos);

int main(int argc, char* argv[])
{
    int i;
    int j;
    int* a = NULL;
    int number = 100;  // Ҫ��Ľ׳���
    int digit = 0;     // �׳˵�λ��
    double sum = 0;
    int pos = 0;

    // ����׳˵�λ��
    for (i = 1; i <= number; ++i)
    {
        sum += log10((double)i);
    }
    digit = (int)(sum + 1);

    a = (int*)malloc(digit * sizeof(int));

    if (!a)
    {
        printf("�ڴ����ʧ��\n");
        return 0;
    }

    for (j = 0; j != digit; ++j)
    {
        a[j] = 0;
    }

    a[0] = 1;

    for (i = 2; i <= number; ++i)
    {
        for (j = 0; j <= pos; ++j)
        {
            a[j] *= i;
        }

        pos = factorial(a, pos);
        // printf("pos = %d\n", pos);
    }

    // printf("digit = %d\n", digit);

    for (i = (digit - 1); i >= 0; --i)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}

int factorial(int* a, int pos)
{
    int i;
    int carry = 0;  // ��λֵ
    for (i = 0; i <= pos; ++i)
    {
        a[i] += carry;

        if (a[i] <= 9)
        {
            carry = 0;
        }
        else if ((a[i] > 9) && (i < pos))  // ���λ����δ�ﵽ���λ
        {
            carry = a[i] / 10;
            a[i] = a[i] % 10;
        }
        else if ((a[i] > 9) && (i >= pos))  // ���λ���ѵ������λ
        {
            while (a[i] > 9)  // ѭ����ǰ��λ
            {
                carry = a[i] / 10;
                a[i] = a[i] % 10;
                ++i;
                a[i] = carry;
            }
        }
    }

    return (i - 1);
}

