// Copyright 2017.刘珅珅
// author：刘珅珅
// 查找字符串所有数字并求和
#include <iostream>
#include <string>
using namespace std;

int StringIntSum(string str);

int main(int argc, char* argv [])
{
    string str;
    int n = 256;

    cin >> str;

    if (str.length() > 256)
    {
        str.resize(256);
    }

    //char str[256] = {0};
    int sum = 0;

    //// scanf("%s", str);
    //std::cin >> str;

    sum = StringIntSum(str);

    std::cout << sum << std::endl;
    return 0;
}

int StringIntSum(string str)
{
    int sum = 0;

    for (int i = 0; i != str.length(); ++i)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            cout << str.substr(i) << endl;
            sum += atoi(str.substr(i).c_str());

            while ((str[i] >= '0') && (str[i] <= '9'))
            {
                ++i;
            }
        }

    }

    //while (*string != '\0')
    //{
    //    if ((*string >= '0') && (*string <= '9'))
    //    {
    //        sum += atoi(string);

    //        while ((*string >= '0') && (*string <= '9'))
    //        {
    //            // printf("%s\n", string);
    //            ++string;
    //        }
    //    }
    //    ++string;
    //}

    return sum;
}

