// Copyright 2019.刘珅珅
// author：刘珅珅
// 数字三角形
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param triangle: a list of lists of integers
    * @return: An integer, minimum path sum
    */
    int minimumTotal1(vector<vector<int>> &triangle) {
        // write your code here
        int n = triangle.size();
        if (n == 0 || triangle[0].size() == 0)
        {
            return 0;
        }

        int m = triangle[n - 1].size();

        // dp[i][j]表示从(0,0)到(i,j)的最小路径和
        // dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
        // 到达(i,j)只有两条路径，即从(i-1,j-1)或从(i-1,j)
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (j == 0)  // 左边界
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    continue;
                }

                if (j == triangle[i].size() - 1)  // 右边界
                {
                    // 只能从上一行的最右端点(i-1,j-1)到达(i,j)
                    dp[i][j] = dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][j];
                    continue;
                }

                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }

        // 查找dp[n - 1]的最小值
        int result = dp[n - 1][0];
        for (int i = 1; i < triangle[n - 1].size(); ++i)
        {
            result = min(result, dp[n - 1][i]);
        }
        return result;
    }

    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        int n = triangle.size();
        if (n == 0 || triangle[0].size() == 0)
        {
            return 0;
        }

        int m = triangle[n - 1].size();

        // 从minimumTotal1中可以看出dp[i]只和dp[i-1]相关
        // 状态转移方程转变为dp[j]=min(dp[j],dp[j-1])+triangle[i][j]
        vector<int> dp(m, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            // 内层的for循环下标是从大到小开始的，与二维情况下的内层for循环不同
            // 参考92.背包问题，这种降维的情况，貌似都是如此
            // https://www.jianshu.com/p/918ca2aff350
            // 个人理解：一维的状态转移方程是从dp[j]->dp[j-1]，所以从大到小
            // 二维情况下，用的是不同行的dp[i][j]->dp[i-1][j-1]
            for (int j = triangle[i].size() - 1; j >= 0; --j)
            {
                if (j == 0)  // 左边界
                {
                    dp[j] = dp[j] + triangle[i][j];
                    continue;
                }

                if (j == triangle[i].size() - 1)  // 右边界
                {
                    // 只能从上一行的最右端点(i-1,j-1)到达(i,j)
                    dp[j] = dp[triangle[i - 1].size() - 1] + triangle[i][j];
                    continue;
                }

                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
        }

        // 查找dp的最小值
        int result = dp[0];
        for (int i = 1; i < dp.size(); ++i)
        {
            result = min(result, dp[i]);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
