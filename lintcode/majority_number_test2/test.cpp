// Copyright 2019.刘珅珅
// author：刘珅珅
// 主元素II
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int majorityNumber(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    int majority_number = 0;
    int candidate1 = INT_MIN;  // 候选数字1
    int candidate2 = INT_MIN;  // 候选数字2
    int count1 = 0;
    int count2 = 0;

    // 采用抵消法：如果3个数字互不相同，则抵消掉，剩下的元素中肯定有主元素
    // 假设有10个元素，严格大于1/3的主元素应包含至少4个相同数字，
    // 如果有3个元素互不相同，剔除掉这3个元素，剩下的7个元素还是存在3个相同数字
    // 剔除掉的3个元素中至多包含1个主元素所对应的数字
    // 初始时candidate1为nums[0]，假设num[0]与nums[1]不同
    // 则candidate2为nums[1]，如果nums[2]与candidate1和candidate2都不同
    // 则count1和count2都减1，相当于抵消一次
    for (int i = 0; i < nums.size(); ++i)
    {
        if (candidate1 == nums[i])
        {
            ++count1;
        }
        else if (candidate2 == nums[i])
        {
            ++count2;
        }
        else if (count1 == 0)  // count1被抵消为0，重新开始获取候选值
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else  // 抵消1次
        {
            --count1;
            --count2;
        }
    }
    count1 = count2 = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == candidate1)
        {
            ++count1;
        }
        else if (nums[i] == candidate2)
        {
            ++count2;
        }
    }
    majority_number = count1 > count2 ? candidate1 : candidate2;
    return majority_number;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 99,2,99,2,99,3,3 };
    cout << majorityNumber(vec) << endl;
    vector<int> vec1{ 1, 2, 1, 2, 1, 3, 3 };
    cout << majorityNumber(vec1) << endl;
    return 0;
}
