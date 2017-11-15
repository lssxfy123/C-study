// 无符号数和有符号数
#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = -1;
    unsigned int b = 0;

    int c = 2147483647;
    int d = -2147483648 - 1; // 产生了溢出，d = 2147483647

    int e = 2147483647;
    unsigned int f = 2147383648;
    
    unsigned int g = 0;
    int h = 0;

    unsigned int k = 1;
    int m = -9;

    short int m1 = -1;
    unsigned short int n = 65535;

    if (a < b)
    {
        printf("a < b\n");
    }
    else if (a == b)
    {
        printf("a = b \n");
    }
    else
    {
        printf("a > b \n");
    }

    if (c < d)
    {
        printf("c < d\n");
    }
    else if (c == d)
    {
        // printf("%d\n", d);
        printf("c = d \n");
    }
    else
    {
        printf("c > d \n");
    }

    if (h < (g - 1))
    {
        printf("%u\n", (g - 1));
        printf("h < (g - 1)\n");
    }


    k = m + 8;  // m被当成无符号数处理

    printf("%u\n", k);  // 4294967295，这是-9的补码转换为无符号数的值再加上8得到的值

    m1 = n - 9;
    printf("%d\n", m1);  // -10，将n当成有符号数处理，其值为-1


    return 0;
}



