// Copyright 2019.刘珅珅
// author：刘珅珅
// 最长上升子序列
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int longestIncreasingSubsequence(vector<int> &nums) {
    // write your code here
    if (nums.size() < 2)
    {
        return nums.size();
    }
 
    // sequence[i]表示第i+1元素结尾的最大上升子序列的长度
    // 默认为1，表示以它结尾的上升子序列只有一个元素
    vector<int> sequece(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // 动态规划
            // 如果nums[i]>nums[j]，则表示以nums[j]结尾的上升子序列
            // 可以添加nums[i]构成新的上升子序列
            // sequence[j]+1表示将0-j的最大上升子序列添加nums[i]后形成的子序列的长度
            // 如果其大于sequence[i]，则更新sequence[i]
            if (nums[i] > nums[j] && sequece[j] + 1 > sequece[i])
            {
                sequece[i] = sequece[j] + 1;
            }
        }
    }

    int max_long_sequence = 0;
    // 查找sequnce的最大值
    // sequence的有可能是无序的，如果某个元素不在最大上升子序列中
    // 则其值为1
    for (int i = 0; i < nums.size(); ++i)
    {
        if (sequece[i] > max_long_sequence)
        {
            max_long_sequence = sequece[i];
        }
    }

    return max_long_sequence;
}

int longestIncreasingSubsequence1(vector<int> &nums) {
    // write your code here
    if (nums.size() < 2)
    {
        return nums.size();
    }

    // 类似栈的功能
    vector<int> sequece(nums.size(), INT_MIN);
    int top = 0;  // top+1最大上升子序列的长度
    sequece[top] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        // 如果nums[i]>栈顶元素
        // 则将nums[i]入栈
        if (nums[i] > sequece[top])
        {
            ++top;
            sequece[top] = nums[i];
        }
        else if (nums[i] == sequece[top])
        {
            continue;
        }
        else
        {
            // nums[i]<sequence[top]
            // 查找栈中第一个大于num[i]的元素
            // 然后用nums[i]替换它，这样是用来增大其“潜力”
            // 例：原序列为1，5，8，3，6，7
            // 栈为1，5，8，此时读到3，用3替换5，得到1，3，8； 
            // 再读6，用6替换8，得到1，3，6；
            // 再读7，得到最终栈为1，3，6，7。最长递增子序列为长度4。
            int low = 0;
            int high = top;
            while (low + 1 < high)
            {
                int middle = low + (high - low) / 2;
                if (nums[i] < sequece[middle])
                {
                    // 不能退出while循环，要继续查找
                    // 直到找到第一个小于nums[i]的元素
                    high = middle;
                }
                else
                {
                    low = middle;
                }
            }

            if (sequece[low] > nums[i])
            {
                sequece[low] = nums[i];
            }
            else
            {
                sequece[high] = nums[i];
            }
        }
    }

    return top + 1;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 4, 2, 4, 5, 3, 7 };
    cout << longestIncreasingSubsequence(vec) << endl;
    return 0;
}
