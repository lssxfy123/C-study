// ÉîÛÚ»ªÎªÕĞÆ¸

#include <stdio.h>
#include <math.h>

int IsPrimeNumber(int number);

int main(int argc, char* argv[])
{
    int begin = 0;
    int end = 0;
    int temp = 0;
    int i;

    scanf("%d %d", &begin, &end);

    if (begin > end)
    {
        temp = begin;
        begin = end;
        end = temp;
    }

    for (i = begin; i <= end; ++i)
    {
        if (IsPrimeNumber(i) == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}

int IsPrimeNumber(int number)
{
    int i;
    int begin = 2;
    int end = (int)(sqrt(number));

    if (number < 2)
    {
        return 0;
    }

    for (i = begin; i <= end; ++i)
    {
        if ((number % i) == 0)
        {
            return 0;
        }
    }

    return 1;
}

