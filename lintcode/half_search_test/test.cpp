// Copyright 2018.刘珅珅
// author：刘珅珅
// 折半查找
#include <iostream>
#include <vector>
#include "..\..\include\print.hpp"
using namespace std;

int binarySearch(vector<int> &nums, int target) {
    // write your code here
    if (nums.size() == 0)
    {
        return -1;
    }

    size_t start = 0;
    size_t end = nums.size() - 1;
    size_t middle;
    
    while (start + 1 < end)
    {
        middle = start + (end - start) / 2;
        if (nums[middle] == target)
        {
            end = middle;  // 这里不能直接返回，要查找第一次出现的下标
        }
        else if (nums[middle] < target)
        {
            start = middle;
        }
        else
        {
            end = middle;
        }
    }

    if (nums[start] == target)
    {
        return start;
    }

    if (nums[end] == target)
    {
        return end;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    return 0;
}
