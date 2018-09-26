// Copyright 2018.刘珅珅
// author：刘珅珅
// 数组剔除自身元素后的乘积
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<long long> productExcludeItself(vector<int> &nums) {
    // write your code here
    vector<long long> result;
    if (nums.size() == 0)
    {
        return result;
    }
    vector<long long> tmp(nums.size(), 1);
    // 第一个循环tmp[i]存储nums[i]右边所有元素的乘积
    for (int i = nums.size() - 2; i >= 0; --i)
    {
        tmp[i] = tmp[i + 1] * nums[i + 1];
    }

    long long tmp1 = 1;
    // tmp1存储为nums[i]左边所有元素乘积
    // tmp1 * tmp[i]为刨除nums[i]所有元素乘积
    for (int i = 0; i < nums.size(); ++i)
    {
        result.push_back(tmp[i] * tmp1);
        tmp1 *= nums[i];
    }

    return result;
}

int main(int argc, char* argv[])
{
    vector<int> v1{ 1, 2, 3 };
    vector<long long> result = productExcludeItself(v1);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ",";
    }
    cout << endl;
    return 0;
}
