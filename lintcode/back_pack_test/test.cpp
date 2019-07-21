// Copyright 2019.刘珅珅
// author：刘珅珅
// 背包问题
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int backPack(int m, vector<int> &A) {
    // write your code here
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }

    // dp[i][j]表示前i个物品在容量为j的背包中最多能放入的重量
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j >= A[i - 1])
            {
                // 包含不选择第i个物品和选择第i个物品
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

// 降维处理
int backPack1(int m, vector<int> &A) {
    // write your code here
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }

    // dp[j]表示容量为j的背包中最多能放入的重量
    // 从backPack函数中可以看出动态规划的状态转移方程
    // 第1个维度i只与i-1相关，所以可以降维
    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j >= A[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
        }
    }
    return dp[m];
}


int main(int argc, char* argv[])
{
    vector<int> vec{ 3, 4, 8, 5 };
    cout << backPack1(10, vec) << endl;
    vector<int> vec1{2, 3, 5, 7};
    cout << backPack1(12, vec1) << endl;
    return 0;
}
