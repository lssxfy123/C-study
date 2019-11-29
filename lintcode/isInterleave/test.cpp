// Copyright 2019.刘珅珅
// author：刘珅珅
// 交叉字符串
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

bool isInterleave(string &s1, string &s2, string &s3) {
    // write your code here
    if (s1.length() + s2.length() != s3.length())
    {
        return false;
    }

    // 使用动态规划求解，dp[i][j]表示s3
    // 的前i+j位是否由s1的前i位，s2的前j位交叉而成(即使dp[i][j]为false也不代表s3就不是由s1和s2交叉构成)
    // 二维数据多分配一行一列，用于存储s3只匹配s1和s3只匹配s2
    vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));

    // 代表s1和s2都为空字符串,s3也为空(如果不为空，之前就会返回false)，所以为true
    dp[0][0] = true;

    // 只匹配s3和s1
    for (int i = 1; i <= s1.length(); ++i)
    {
        dp[i][0] = dp[i - 1][0] && s3[i - 1] == s1[i - 1];
    }

    // 只匹配s3和s2
    for (int j = 1; j <= s2.length(); ++j)
    {
        dp[0][j] = dp[0][j - 1] && s3[j - 1] == s2[j - 1];
    }

    for (int i = 1; i <= s1.length(); ++i)
    {
        for (int j = 1; j <= s2.length(); ++j)
        {
            // s3如果由s1和s2交叉构成，只有向下走和向右走两种情况
            // 向下走，取s1的值
            if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
            {
                dp[i][j] = true;
            }
            // 向右走，取s2的值
            else if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
            {
                dp[i][j] = true;
            }
        }
    }
    return dp[s1.length()][s2.length()];

}

int main(int argc, char* argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "daabbcbcac";
    cout << isInterleave(s1, s2, s3) << endl;
    return 0;
}
