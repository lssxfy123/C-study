// Copyright 2018.���|�|
// author�����|�|
// �ж��ַ����Ƿ��ظ��ַ�
#include <iostream>
#include <algorithm>
#include "../../include/print.hpp"
using namespace std;

bool isUnique(string &str) {
    // write your code here
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length() - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    return 0;
}

