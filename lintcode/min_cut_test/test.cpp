// Copyright 2019.刘珅珅
// author：刘珅珅
// 分隔回文串 II
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param s: A string
    * @return: An integer
    */
    int minCut(string &s) {
        // write your code here
        int n = s.length();
        if (n < 2)
        {
            return 0;
        }

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // isPalindrome[j][i]表示从j到i的子串是否为回文串
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (i == j)
                {
                    isPalindrome[j][i] = true;
                    continue;
                }

                if (i - j == 1)
                {
                    isPalindrome[j][i] = (s[i] == s[j]) ? true : false;
                    continue;
                }

                // 从j到i的字符串是否回文，就是其两端字符剔除掉后的字符串是否回文并且两端字符是否相等
                isPalindrome[j][i] = isPalindrome[j + 1][i - 1] && (s[i] == s[j]) ? true : false;
            }
        }

        // 表示前i个字符串最小切割次数
        vector<int> dp(n + 1, 0);
        // 必须初始化为-1，这样如果前i个字符串是回文的dp[0]+1就是0
        dp[0] = -1;
        for (int i = 1; i <= n; ++i)
        {
            // 前i个字符串最大切割次数为i-1
            dp[i] = i - 1;
            for (int j = 0; j < i; ++j)
            {
                // dp[j]表示前j个字符串的最小切割数
                // 如果从j到i个字符串是回文的
                // dp[i] = min(dp[i], dp[j]+1)
                // dp[0]=-1，如果isPalindrome[0][i-1]为true
                // 即前i个字符串本身是回文的，dp[i]肯定为dp[0]+1为0
                // 如果前i个字符串不回文，则为dp[j]+1且从j到i-1字符串是回文的
                if (isPalindrome[j][i - 1])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string tmp = "aabaa";
    cout << s.minCut(tmp) << endl;
    return 0;
}
