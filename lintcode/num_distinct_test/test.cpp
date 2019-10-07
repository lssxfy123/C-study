// Copyright 2019.刘珅珅
// author：刘珅珅
// 不同的子序列
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param S: A string
    * @param T: A string
    * @return: Count the number of distinct subsequences
    */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (S.length() < T.length())
        {
            return 0;
        }

        if (T.length() == 0)
        {
            return 1;
        }

        int result = 0;

        // dp[i][j]表示S的前i个字符中包含多少个T的前j个字符的子序列
        vector<vector<int>> dp(S.length() + 1, vector<int>(T.length() + 1, 0));
        // j=0表示T为空，则dp[i][0]全部为1
        for (int i = 0; i <= S.length(); ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= S.length(); ++i)
        {
            for (int j = 1; j <= T.length(); ++j)
            {
                // 首先S的前i个字符和前i-1个字符（即不考虑S[i-1]）针对T的前j个字符
                // 的子序列个数至少是相同的，即dp[i][j]>=dp[i-1][j]
                // 所以首先dp[i][j]=dp[i-1][j]
                // 注意：dp[i][j]包含dp[i-1][j]情况，但不一定包含dp[i-1][j-1]
                // 例：dp[i-1][j-1]=1，但dp[i][j]有可能是0
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1])
                {
                    // dp[i-1][j-1]表示S的前i-1个字符包含T的前j-1个字符的子序列个数
                    // 如果S[i-1]==T[j-1]，则dp[i][j]要加上dp[i-1][j-1]
                    // 原因是S[i-1]==T[j-1]，则将其分别剔除掉，就是dp[i-1][j-1]
                    // dp[i][j]就包含了dp[i-1][j-1]
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[S.length()][T.length()];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string S = "rabbbit";
    string T = "rabbit";
    cout << s.numDistinct(S, T) << endl;
    return 0;
}
