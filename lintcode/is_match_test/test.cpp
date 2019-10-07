
// Copyright 2019.���|�|
// author�����|�|
// ������ʽƥ��
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

        // dp[i][j]��ʾsǰi���ַ���������ʽpǰj���ַ���ƥ�����
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        // ���������ʽΪ�գ���j=0����dp[0][0]=true
        // ���������dp[i][0]=false
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
                // ���������ʽΪ�գ���j=0����ƥ���ַ���ҲΪ�գ���i=0
                // ��dp[0][0]=true
                if (i == 0 && j == 0)
                {
                    dp[i][j] = true;
                    continue;
                }

                // ���������ʽΪ�գ�����ƥ���ַ�����Ϊ��
                if (j == 0)
                {
                    dp[i][j] = false;
                    continue;
                }

                if (p[j - 1] == '*')
                {
                    // s="a",p="ab*"��dp[i][j]ƥ�䣬��Ϊ����*��������
                    // ��ǰ����ַ�b���Գ���0�λ��Σ�����dp[i][j]=dp[i][j-2]
                    // dp[i][j-2]��s="a",p="a"��ƥ���������Ȼ��ƥ���
                    bool tmp1 = (j > 1 && dp[i][j - 2]);

                    // Ҳ��*�������壬s="a",p="a*"
                    bool tmp2 = dp[i][j - 1];

                    // s="abc" p="ab.*"��p="abc*"
                    bool tmp3 = (i > 0 && j > 1 && dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                    
                    // dp[i][j]����һ��״̬������3��
                    dp[i][j] = tmp1 || tmp2 || tmp3;

                }
                else
                {
                    // ����s="abc" pΪ"abc"��"ab."�����������
                    // dp[i][j]�Ƿ�ƥ���s="ab",p="ab"��ƥ�����һ��
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
