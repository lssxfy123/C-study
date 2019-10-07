// Copyright 2019.刘珅珅
// author：刘珅珅
// 不同的二叉查找树
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param n: An integer
    * @return: An integer
    */
    int numTrees(int n) {
        // write your code here
        if (n <= 1)
        {
            return 1;
        }

        // 卡特兰数
        // http://blog.sina.com.cn/s/blog_5ce680a40102vqgu.html
        // 状态转移方程dp[n]=dp[n-1]*dp[0]+dp[n-2]*dp[1]+dp[n-3]dp[2]+...+dp[1]*dp[n-2]+dp[0]*dp[n-1]
        // dp[i]表示1-i能构成的二叉查找树
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
