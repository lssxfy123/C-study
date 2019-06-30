// Copyright 2019.刘珅珅
// author：刘珅珅
// 字符大小写排序
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

void sortLetters(string &chars) {
    // write your code here
    if (chars.length() == 0)
    {
        return;
    }

    // 一遍快速排序
    int i = 0, j = chars.length() - 1;
    while (i <= j)
    {
        // 从左向右，找到第1个大写字符
        while (i <= j && isLower(chars[i]))
        {
            ++i;
        }

        // 从右向左，找到第1个小写字符
        while (i <= j && !isLower(chars[j]))
        {
            --j;
        }

        if (i < j)
        {
            swap(chars[i], chars[j]);
        }
    }

}

int main(int argc, char* argv[])
{
    string s1 = "abABcdafeEafaBD";
    sortLetters(s1);
    cout << s1 << endl;
    string s2 = "ABC";
    sortLetters(s2);
    cout << s2 << endl;
    return 0;
}
