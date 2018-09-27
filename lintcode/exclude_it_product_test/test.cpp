// Copyright 2018.���|�|
// author�����|�|
// �����޳�����Ԫ�غ�ĳ˻�
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
    // ��һ��ѭ��tmp[i]�洢nums[i]�ұ�����Ԫ�صĳ˻�
    for (int i = nums.size() - 2; i >= 0; --i)
    {
        tmp[i] = tmp[i + 1] * nums[i + 1];
    }

    long long tmp1 = 1;
    // tmp1�洢Ϊnums[i]�������Ԫ�س˻�
    // tmp1 * tmp[i]Ϊ�ٳ�nums[i]����Ԫ�س˻�
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
