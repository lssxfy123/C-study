// Copyright 2019.刘珅珅
// author：刘珅珅
// 出现次数最多的字母
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int mostFrequentlyAppearingLetters(string &str) {
    // Write your code here.
    int max_length = 0;

    // 只存在大写字母或小写字母
    vector<int> tmp(256, 0);
    for (int i = 0; i < str.size(); ++i)
    {
        tmp[str[i]]++;
    }

    for (int i = 0; i < tmp.size(); ++i)
    {
        if (tmp[i] > max_length)
        {
            max_length = tmp[i];
        }
    }

    return max_length;
}

int main(int argc, char* argv[])
{
    return 0;
}
