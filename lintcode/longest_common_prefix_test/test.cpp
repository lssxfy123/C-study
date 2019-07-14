// Copyright 2019.刘珅珅
// author：刘珅珅
// 最长公共前缀
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    // write your code here
    if (strs.size() == 0)
    {
        return "";
    }

    string result = strs[0];
    int min_index = 0;
    for (int i = 1; i < strs.size(); ++i)
    {
        if (strs[i].size() < result.size())
        {
            min_index = i;
        }
    }

    if (min_index != 0)
    {
        result = strs[min_index];
    }

    if (result.size() == 0)
    {
        return result;
    }

    int len = result.length();
    for (int i = 0; i < strs.size(); ++i)
    {
        if (i != min_index)
        {
            if (strs[i].substr(0, len).compare(result) != 0)
            {
                result.pop_back();
                len = result.size();
                i = -1;
            }
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    vector<string> strs{ "ABCD","ABEF","ACEF" };
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
