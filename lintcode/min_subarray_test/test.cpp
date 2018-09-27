// Copyright 2018.刘珅珅
// author：刘珅珅
// 最小子数组
#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int minSubArray(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    int min_value = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] < min_value)
        {
            min_value = nums[i];
        }
    }

    if (min_value >= 0)
    {
        return min_value;
    }

    int tmp = 0;
    int min_sum = min_value;
    for (int i = 0; i < nums.size(); ++i)
    {
        tmp += nums[i];
        if (tmp < min_sum)
        {
            min_sum = tmp;
        }
        else if (tmp > 0)
        {
            tmp = 0;
        }
    }

    return min_sum;
}

int minSubArray1(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    int tmp = 0;
    int min_sum = nums[0];  // 将第一个值默认为最小值,求最大子序列也可如此
    for (int i = 0; i < nums.size(); ++i)
    {
        tmp += nums[i];
        if (tmp < min_sum)
        {
            min_sum = tmp;
        }
        else if (tmp > 0)
        {
            tmp = 0;
        }
    }

    return min_sum;
}

int main(int argc, char* argv[])
{
    vector<int> array;
    array.push_back(-2);
    array.push_back(11);
    array.push_back(-4);
    array.push_back(13);
    array.push_back(-5);
    array.push_back(-2);
    cout << minSubArray(array) << endl;
    cout << minSubArray1(array) << endl;
    return 0;
}
