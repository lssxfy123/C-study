// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// ×Ö·û´®²éÕÒ
#include <iostream>
#include "..\..\include\print.hpp"
using namespace std;

int strStr(const char *source, const char *target) {
    // write your code here
    int reslut_index = -1;
    if (source == nullptr || target == nullptr)
    {
        return reslut_index;
    }

    int src_length = strlen(source);
    int target_length = strlen(target);
    int marks[256];
    for (int i = 0; i < 256; ++i)
    {
        marks[i] = -1;
    }

    for (int i = target_length - 1; i >= 0; --i)
    {
        if (marks[target[i]] == -1)
        {
            marks[target[i]] = target_length - i;
        }
    }

    int i = 0;
    int j = src_length - target_length + 1;
    int k = 0;
    while (i < j)
    {
        for (k = 0; k < target_length; ++k)
        {
            if (source[i + k] != target[k])
            {
                break;
            }
        }

        if (k == target_length)
        {
            reslut_index = i;
            return reslut_index;
        }

        k = marks[source[i + target_length]];
        if (k == -1)
        {
            i = i + target_length + 1;
        }
        else
        {
            i += k;
        }
    }

    return reslut_index;
}

int main(int argc, char* argv[])
{
    char* src = "abcdabcdefg";
    char* target = "bcd";
    cout << strStr(src, target) << endl;
    return 0;
}
