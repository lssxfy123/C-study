// Copyright 2018.刘珅珅
// author：刘珅珅
// 逐个反转字符串中每个单词
// 反转后：去掉前后空格
// 单词之间只能有1个空格
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// 删除首尾空格
void trim(string& s)
{
    if (s.empty())
    {
        return;
    }

    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

string reverseWords(string &s) {
    // write your code here
    string result = "";
    trim(s);
    int start = 0;
    int end = 0;
    while (start >= 0)
    {
        start = s.find_last_of(" ");
        if (start < 0)
        {
            result.append(" ");
            result.append(s);
            break;
        }
        string tmp = s.substr(start);
        result.append(tmp);
        s = s.substr(0, start);
        trim(s);
    }
    trim(result);
    return result;
}

string reverseWords1(string& s)
{
    string result;
    int i = s.length() - 1;
    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        if (i < 0) break;
        if (result.length() != 0)
            result.push_back(' ');
        string temp;
        for (; i >= 0 && s[i] != ' '; i--)
            temp.push_back(s[i]);
        reverse(temp.begin(), temp.end());
        result.append(temp);
    }
    s = result;
    return s;
}

string reverseWords2(string& s)
{
    string result = "";
    vector<string> tmp;
    int start = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            if (start < 0)
            {
                continue;
            }
            else
            {
                tmp.push_back(s.substr(start, i - start));
                start = -1;
                continue;
            }
        }
        else if (i == s.size() - 1)
        {
            tmp.push_back(s.substr(start));
        }

        if (start < 0)
        {
            start = i;
        }
    }

    for (vector<string>::reverse_iterator itor = tmp.rbegin(); itor != tmp.rend(); ++itor)
    {
        result.append(*itor);
        result.append(" ");
    }

    s = result;
    return s;
}


int main(int argc, char* argv[])
{
    string s = "the  sky is   blue";
    string result = reverseWords2(s);
    cout << result << endl;
    string s1 = "world";
    result = reverseWords2(s1);
    cout << result << endl;
    return 0;
}
