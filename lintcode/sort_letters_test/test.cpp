// Copyright 2019.���|�|
// author�����|�|
// �ַ���Сд����
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

    // һ���������
    int i = 0, j = chars.length() - 1;
    while (i <= j)
    {
        // �������ң��ҵ���1����д�ַ�
        while (i <= j && isLower(chars[i]))
        {
            ++i;
        }

        // ���������ҵ���1��Сд�ַ�
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
