// Copyright 2019.刘珅珅
// author：刘珅珅
// 编辑距离
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param word1: A string
    * @param word2: A string
    * @return: The minimum number of steps.
    */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int row = word1.length() + 1;
        int col = word2.length() + 1;

        // dp[i][j]表示word1的前i个字符转换为word2的前j个字符需要的最小次数
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // word1转换为word2的前0个字符
        // 即转换为空字符次数
        // 全部为删除操作dp[i][0]=i
        for (int i = 0; i < row; ++i)
        {
            dp[i][0] = i;
        }

        // 空字符转换为word2的前j个字符
        // 全部为插入操作dp[0][j]=j
        for (int j = 0; j < col; ++j)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                // 从上一个状态转换到dp[i][j]总共有3种操作
                // 1. 添加：给word1前i个字符插入一个和word2前j个字符
                // 的最后一个字符相同的字符,这个操作次数为1，
                // 即dp[i][j]=dp[i][j-1]+1
                // 例：从ab-->cd，可以计算从ab-->c的次数(即dp[i][j-1])，然后再插入d
                // 2. 删除：删除word1前i个字符的最后一个字符，然后把前i-1个字符转换为
                // word2的前j个字符，即dp[i][j]=dp[i-1][j]+1
                // 例：从ab-->cd，计算从a-->cd的次数，再删除b
                // 3. 替换：把word1前i个字符的最后一个字符替换为word2前j个字符的最后一个字符
                // 这里分为两种情况，如果word1[i-1]==word2[j-1]，则不需要替换，即dp[i][j]=dp[i-1][j-1]
                // 如果不相等,则dp[i][j]=dp[i-1][j-1]+1
                // 最后取这3种情况的最小距离
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
        return dp[row - 1][col - 1];
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
