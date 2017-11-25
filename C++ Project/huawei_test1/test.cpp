// Copyright 2017.刘珅珅
// author：刘珅珅
// 查找字符串所有数字并求和
#include <iostream>

int StringIntSum(const char* string);

int main(int argc, char* argv [])
{

    char str[256] = {0};
    int sum = 0;

    std::cin >> str;

    sum = StringIntSum(str);

    std::cout << sum << std::endl;
    return 0;
}

int StringIntSum(const char* string)
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


