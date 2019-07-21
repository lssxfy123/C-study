// Copyright 2019.刘珅珅
// author：刘珅珅
// 第一个只出现一次的字符
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../include/print.hpp"
using namespace std;

char firstUniqChar(string &str) {
    // Write your code here
    if (str.size() == 0)
    {
        return ' ';
    }

    // 用vector容器，索引为字符的大小，值为出现的次数
    // 先找到最大字符
    int max_length = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] > max_length)
        {
            max_length = str[i];
        }
    }

    vector<int> tmp(max_length + 1, 0);

    for (int i = 0; i < str.size(); ++i)
    {
        tmp[str[i]]++;
    }

    for (int i = 0; i < tmp.size(); ++i)
    {
        if (tmp[i] == 1)
        {
            return i;
        }
    }

}

int main(int argc, char* argv[])
{
    string str = "abaccdeff";
    cout << firstUniqChar(str) << endl;
    return 0;
}
