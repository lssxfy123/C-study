// Copyright 2019.���|�|
// author�����|�|
// �ָ����Ĵ� II
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

        // isPalindrome[j][i]��ʾ��j��i���Ӵ��Ƿ�Ϊ���Ĵ�
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

                // ��j��i���ַ����Ƿ���ģ������������ַ��޳�������ַ����Ƿ���Ĳ��������ַ��Ƿ����
                isPalindrome[j][i] = isPalindrome[j + 1][i - 1] && (s[i] == s[j]) ? true : false;
            }
        }

        // ��ʾǰi���ַ�����С�и����
        vector<int> dp(n + 1, 0);
        // �����ʼ��Ϊ-1���������ǰi���ַ����ǻ��ĵ�dp[0]+1����0
        dp[0] = -1;
        for (int i = 1; i <= n; ++i)
        {
            // ǰi���ַ�������и����Ϊi-1
            dp[i] = i - 1;
            for (int j = 0; j < i; ++j)
            {
                // dp[j]��ʾǰj���ַ�������С�и���
                // �����j��i���ַ����ǻ��ĵ�
                // dp[i] = min(dp[i], dp[j]+1)
                // dp[0]=-1�����isPalindrome[0][i-1]Ϊtrue
                // ��ǰi���ַ��������ǻ��ĵģ�dp[i]�϶�Ϊdp[0]+1Ϊ0
                // ���ǰi���ַ��������ģ���Ϊdp[j]+1�Ҵ�j��i-1�ַ����ǻ��ĵ�
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
