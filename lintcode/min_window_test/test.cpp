// Copyright 2019.刘珅珅
// author：刘珅珅
// 最小子串覆盖
#include <iostream>
#include <unordered_map>
#include "../../include/print.hpp"
using namespace std;

string minWindow(string &source, string &target) {
    // write your code here
    if (source.length() < target.length())
    {
        return "";
    }

    if (source.length() == 0)
    {
        return "";
    }

    // target为空字符串，返回source
    if (target.length() == 0)
    {
        return source;
    }

    unordered_map<char, int> refs;
    string result = "";
    for (int i = 0;i < target.length(); ++i)
    {
        if (refs.count(target[i]) == 0)
        {
            refs[target[i]] = 1;
        }
        else
        {
            refs[target[i]]++;
        }
    }

    int count = refs.size();
    int k = 0;
    int len = source.length() + 1;
    for (int j = 0; j < source.length(); ++j)
    {
        while (k < source.length() && count > 0)
        {
            --refs[source[k]];
            if (refs[source[k]] == 0)
            {
                --count;
            }
            ++k;

            if (count == 0)
            {
                break;
            }
        }

        if (count == 0 && k - j < len)
        {
            len = k - j;
            result = source.substr(j, k - j);
        }

        if (refs[source[j]] == 0)
        {
            ++count;
        }
        refs[source[j]]++;
    }


    return result;
}

string minWindow1(string &source, string &target) {
    // write your code here
    if (source.length() < target.length())
    {
        return "";
    }

    if (source.length() == 0)
    {
        return "";
    }

    // target为空字符串，返回source
    if (target.length() == 0)
    {
        return source;
    }

    unordered_map<char, int> refs;
    string result = "";
    for (int i = 0; i < target.length(); ++i)
    {
        if (refs.count(target[i]) == 0)
        {
            refs[target[i]] = 1;
        }
        else
        {
            refs[target[i]]++;
        }
    }

    int count = 0;
    int k = 0;
    int len = source.length() + 1;
    for (int j = 0; j < source.length(); ++j)
    {
        if (refs.count(source[j]) == 0)
        {
            continue;
        }

        // 第一次while循环找到的k
        while (k < source.length() && count != refs.size())
        {
            if (refs.find(source[k]) != refs.end())
            {
                --refs[source[k]];

                // refs[key]==0，表明已经查找到满足target中key的个数的字符key
                if (refs[source[k]] == 0)
                {
                    ++count;
                }
            }
            ++k;
        }

        if (count == refs.size() && k - j < len)
        {
            len = k - j;
            result = source.substr(j, k - j);
        }

        // refs[key]<0，表明之前while循环得到的前k个字符中
        // 字符key的个数大于target中字符key的个数，这时不改变count
        // 如果count==refs.size()，下一轮循环就会将之前的result进行缩减
        // 如果refs[key]==0，表明前k个字符中的字符key的个数等于target中
        // 字符key的个数，这时修改count，使上面的while循环重新开始向后查询
        // 如果重新使count==refs.size()，j就是新的子串的起始位置，如果k-j小于
        // 之前子串的长度，就更新result
        // refs[key]>0，表明j大于之前的k值
        if (refs[source[j]]++ >= 0)
        {
            --count;
        }
    }


    return result;
}


int main(int argc, char* argv[])
{
    string src = "BADOBECODEBANC";
    string target = "AABC";
    cout << minWindow1(src, target) << endl;
    return 0;
}
