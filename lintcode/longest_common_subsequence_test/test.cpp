// Copyright 2019.刘珅珅
// author：刘珅珅
// 最长公共子序列
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// 动态规划
int longestCommonSubsequence(string &A, string &B) {
    // write your code here
    if (A.size() == 0 || B.size() == 0)
    {
        return 0;
    }
    int m = A.size();
    int n = B.size();

    // dp[i][j]表示A的前i个字符和B的前j个字符的最长公共子序列长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // A[i-1]是A的第i个字符，B[j-1]是B的第j个字符
            // 如果A[i-1]==B[j-1]，则A的前i个字符和B的前j个字符的最长公共子序列
            // 就是A的前i-1个字符和B的前j-1个字符的最长公共子序列+A[i-1]或B[j-1]
            // 即dp[i][j]=dp[i-1][j-1]+1
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // 因为A[i-1]!=B[j-1]，则A的前i个字符和B的前j个字符的最长公共子序列有两种可能
                // 可能是A的前i-1个字符和B的前j个字符的最长公共序列或者A的前i个字符
                // 和B的前j-1个字符的最长公共序列
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main(int argc, char* argv[])
{
    string A = "guurdbaxypvwotateuursrhqnzqeqk";
    string B = "qktmyfzeyelbckekldbbhrgbnpzqwo";
    cout << longestCommonSubsequence(A, B) << endl;
    return 0;
}
