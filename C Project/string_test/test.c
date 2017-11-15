// 华为测试题：找出一串字符串中的整数并求和

#include <stdio.h>

int StringIntSum(char* string);

int main(int argc, char* argv [])
{
    char str[256] = {0};
    int sum = 0;

    scanf("%s", str);

    sum = StringIntSum(str);

    printf("%d\n", sum);
    return 0;
}

int StringIntSum(char* string)
{
    int sum = 0;

    while (*string != '\0')
    {
        if ((*string >= '0') && (*string <= '9'))
        {
            sum += atoi(string);

            while ((*string >= '0') && (*string <= '9'))
            {
                // printf("%s\n", string);
                ++string;
            }
        }
        ++string;
    }

    return sum;
}
