// Copyright 2019.刘珅珅
// author：刘珅珅
// 第一个错误的代码版本
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// 替代lintcode中提供的函数
bool isBadVersion(int k)
{
    return false;
}

int findFirstBadVersion(int n) {
    // write your code here
    int start = 1;  // 版本号从1开始
    int end = n;

    while (start + 1 < end)  // 主要是避免start = end - 1或start = end造成的死循环问题
    {
        int middle = start + (end - start) / 2;
        if (isBadVersion(middle))
        {
            // 不能直接跳出循环，要查找第1个错误的版本号
            end = middle;
        }
        else
        {
            start = middle;
        }
    }

    if (isBadVersion(start))
    {
        return start;
    }

    return end;
}

int main(int argc, char* argv[])
{
    return 0;
}
