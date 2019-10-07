
// Copyright 2019.刘珅珅
// author：刘珅珅
// 正则表达式匹配
#include <algorithm>
#include <iostream>
#include <vector>
#include <regex>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param s: A string
    * @param p: A string includes "." and "*"
    * @return: A boolean
    */
    bool isMatch(string &s, string &p) {
        // write your code here
        if (p.length() == 0)
        {
            return false;
        }

        // dp[i][j]表示s前i个字符与正则表达式p前j个字符的匹配情况
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        // 如果正则表达式为空，即j=0，则dp[0][0]=true
        // 其它情况下dp[i][0]=false
        for (int i = 0; i <= s.length(); ++i)
        {
            if (i == 0)
            {
                dp[i][0] = true;
            }
            else

            {
                dp[i][0] = false;
            }
        }


        for (int i = 0; i <= s.length(); ++i)
        {
            for (int j = 0; j <= p.length(); ++j)
            {
                // 如果正则表达式为空，即j=0，待匹配字符串也为空，即i=0
                // 则dp[0][0]=true
                if (i == 0 && j == 0)
                {
                    dp[i][j] = true;
                    continue;
                }

                // 如果正则表达式为空，而待匹配字符串不为空
                if (j == 0)
                {
                    dp[i][j] = false;
                    continue;
                }

                if (p[j - 1] == '*')
                {
                    // s="a",p="ab*"，dp[i][j]匹配，因为根据*的正则含义
                    // 其前面的字符b可以出现0次或多次，所以dp[i][j]=dp[i][j-2]
                    // dp[i][j-2]是s="a",p="a"的匹配情况，显然是匹配的
                    bool tmp1 = (j > 1 && dp[i][j - 2]);

                    // 也是*的正则含义，s="a",p="a*"
                    bool tmp2 = dp[i][j - 1];

                    // s="abc" p="ab.*"或p="abc*"
                    bool tmp3 = (i > 0 && j > 1 && dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                    
                    // dp[i][j]的上一个状态可能有3种
                    dp[i][j] = tmp1 || tmp2 || tmp3;

                }
                else
                {
                    // 例：s="abc" p为"abc"或"ab."，这种情况下
                    // dp[i][j]是否匹配和s="ab",p="ab"的匹配情况一致
                    if (i > 0 &&(s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

int main(int argc, char* argv[])
{
    string s = "aa";
    string p = "aa";
    Solution sl;
    if (sl.isMatch(s, p))
    {
        cout << "match" << endl;
    }
    else
    {
        cout << "no match" << endl;
    }
    return 0;
}
