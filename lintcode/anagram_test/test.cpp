// Copyright 2018.刘珅珅
// author：刘珅珅
// 两个字符串是变位词
#include <iostream>
#include <algorithm>
#include "../../include/print.hpp"
using namespace std;

bool anagram(string &s, string &t) {
    // write your code here
    if (s.length() != t.length())
    {
        return false;
    }

    char tmp[128];
    for (int i = 0; i < 128; ++i)
    {
        tmp[i] = 0;
    }

    for (int i = 0; i < s.length(); ++i)
    {
        tmp[s[i]] += 1;
        tmp[t[i]] -= 1;
    }

    for (int i = 0;i < 128; ++i)
    {
        if (tmp[i] != 0)
        {
            return false;
        }
    }


    return true;
}

int main(int argc, char* argv[])
{
    string s = "abcd";
    string t = "dcab";
    cout << anagram(s, t) << endl;
    return 0;
}

