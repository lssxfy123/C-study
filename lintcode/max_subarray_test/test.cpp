// Copyright 2018.刘珅珅
// author：刘珅珅
// 最大子序列
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int maxSubArray(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    // 查找序列最大值
    int max_value = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > max_value)
        {
            max_value = nums[i];
        }
    }

    int max_sum = max_value;
    int tmp = 0;
    // O(N)时间复杂度
    // 如果tmp为负值，说明nums[i] < 0,i
    // 不可能是最大子序列的起点，
    // 如果max_value < 0，说明序列全为负值，
    // 则最大子序列和就是max_value;
    // 如果max_value >= 0，则最大子序列和 >= max_value，
    // 所以i肯定不会是最大子序列的起点，依次类推，和为负值
    // 的子序列也不能是最大子序列的前缀，可以将tmp置成0，重新
    // 计算后面子序列的和
    for (int i = 0; i < nums.size(); ++i)
    {
        tmp += nums[i];
        if (tmp > max_sum)
        {
            max_sum = tmp;
        }
        else if (tmp < 0)
        {
            tmp = 0;
        }
    }

    return max_sum;

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
    cout << maxSubArray(array) << endl;
    return 0;
}
