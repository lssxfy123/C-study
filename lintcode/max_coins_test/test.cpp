// Copyright 2019.刘珅珅
// author：刘珅珅
// 吹气球
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integer
    * @return: An integer, maximum coins
    */
    int maxCoins(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0)
        {
            return 0;
        }

        int n = nums.size();  // 先将原始长度存储下来
        // 根据题目提示在nums数组两端各添加一个1，方便后面的计算
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j]表示吹爆第i个到第j个气球能获得的最多的分数
        // 对于第i到第j个气球，可以先任意吹爆一个气球k，能获得
        // nums[k]*(k的前一个数)*(k的后一个数)，
        // 但由于不清楚k左边和右边的气球有没有被吹，所以无法确定k左右的数
        // 那么换一种思路：最后吹爆任意一个气球k，那么k左右数字就确定了，
        // 左边肯定是nums[i-1]，右边肯定是nums[j+1],因为此刻第i到第j个气球
        // 只剩下k没有被吹爆，这时获得的分数就是nums[i-1]*nums[k]*nums[j+1]
        // 再加上吹爆k之前获得的最大分数dp[i][k-1]+dp[k+1][j]
        // （即在k之前吹爆的:k左边第i到第k-1个，k右边第k+1到第j个）
        // 状态转移方程：dp[i][j]=max(nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j])
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 1; i <= n - len + 1; ++i)
            {
                int j = i + len - 1;

                // 选择不同的k值
                for (int k = i; k <= j; ++k)
                {
                    int tmp = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    if (dp[i][j] < tmp)
                    {
                        dp[i][j] = tmp;
                    }
                }
            }
        }

        // 最终的输出结果为第1个到第n个
        return dp[1][n];
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
