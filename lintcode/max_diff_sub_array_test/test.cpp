// Copyright 2019.刘珅珅
// author：刘珅珅
// 最大子数组差
#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int maxDiffSubArrays(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    vector<int> left_sum(nums.size(), 0);
    int tmp = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp < 0)
        {
            tmp = 0;
        }
        tmp += nums[i];
        if (tmp > max_sum)
        {
            max_sum = tmp;
        }
        left_sum[i] = max_sum;
    }

    tmp = 0;
    int min_sum = INT_MAX;
    int result1 = INT_MIN;
    for (int j = nums.size() - 1; j > 0; --j)
    {
        if (tmp > 0)
        {
            tmp = 0;
        }
        tmp += nums[j];
        if (tmp < min_sum)
        {
            min_sum = tmp;
        }
        if (abs(left_sum[j - 1] - min_sum) > result1)
        {
            result1 = abs(left_sum[j - 1] - min_sum);
        }
    }

    tmp = 0;
    min_sum = INT_MAX;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp > 0)
        {
            tmp = 0;
        }
        tmp += nums[i];
        if (tmp < min_sum)
        {
            min_sum = tmp;
        }
        left_sum[i] = min_sum;
    }

    tmp = 0;
    max_sum = INT_MIN;
    int result2 = INT_MIN;
    for (int j = nums.size() - 1; j > 0; --j)
    {
        if (tmp < 0)
        {
            tmp = 0;
        }
        tmp += nums[j];
        if (tmp > max_sum)
        {
            max_sum = tmp;
        }
        if (abs(max_sum - left_sum[j - 1]) > result2)
        {
            result2 = abs(max_sum - left_sum[j - 1]);
        }
    }
    return result1 > result2 ? result1 : result2;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 1, 2, -3, 1 };
    cout << maxDiffSubArrays(vec) << endl;
    vector<int> vec1{0, -1};
    cout << maxDiffSubArrays(vec1) << endl;
    vector<int> vec2{ -5,3,-4,0,0,0,-1,20,1,1,-1,-1,-1,-1,-1 };
    cout << maxDiffSubArrays(vec2) << endl;
    return 0;
}
