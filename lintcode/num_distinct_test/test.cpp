// Copyright 2019.���|�|
// author�����|�|
// ��ͬ��������
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

        // dp[i][j]��ʾS��ǰi���ַ��а������ٸ�T��ǰj���ַ���������
        vector<vector<int>> dp(S.length() + 1, vector<int>(T.length() + 1, 0));
        // j=0��ʾTΪ�գ���dp[i][0]ȫ��Ϊ1
        for (int i = 0; i <= S.length(); ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= S.length(); ++i)
        {
            for (int j = 1; j <= T.length(); ++j)
            {
                // ����S��ǰi���ַ���ǰi-1���ַ�����������S[i-1]�����T��ǰj���ַ�
                // �������и�����������ͬ�ģ���dp[i][j]>=dp[i-1][j]
                // ��������dp[i][j]=dp[i-1][j]
                // ע�⣺dp[i][j]����dp[i-1][j]���������һ������dp[i-1][j-1]
                // ����dp[i-1][j-1]=1����dp[i][j]�п�����0
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1])
                {
                    // dp[i-1][j-1]��ʾS��ǰi-1���ַ�����T��ǰj-1���ַ��������и���
                    // ���S[i-1]==T[j-1]����dp[i][j]Ҫ����dp[i-1][j-1]
                    // ԭ����S[i-1]==T[j-1]������ֱ��޳���������dp[i-1][j-1]
                    // dp[i][j]�Ͱ�����dp[i-1][j-1]
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
