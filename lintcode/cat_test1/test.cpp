// Copyright 2019.���|�|
// author�����|�|
// ��һ��ֻ����һ�ε��ַ�
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

    // ��vector����������Ϊ�ַ��Ĵ�С��ֵΪ���ֵĴ���
    // ���ҵ�����ַ�
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
