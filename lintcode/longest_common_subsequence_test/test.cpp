// Copyright 2019.���|�|
// author�����|�|
// �����������
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// ��̬�滮
int longestCommonSubsequence(string &A, string &B) {
    // write your code here
    if (A.size() == 0 || B.size() == 0)
    {
        return 0;
    }
    int m = A.size();
    int n = B.size();

    // dp[i][j]��ʾA��ǰi���ַ���B��ǰj���ַ�������������г���
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // A[i-1]��A�ĵ�i���ַ���B[j-1]��B�ĵ�j���ַ�
            // ���A[i-1]==B[j-1]����A��ǰi���ַ���B��ǰj���ַ��������������
            // ����A��ǰi-1���ַ���B��ǰj-1���ַ��������������+A[i-1]��B[j-1]
            // ��dp[i][j]=dp[i-1][j-1]+1
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // ��ΪA[i-1]!=B[j-1]����A��ǰi���ַ���B��ǰj���ַ�������������������ֿ���
                // ������A��ǰi-1���ַ���B��ǰj���ַ�����������л���A��ǰi���ַ�
                // ��B��ǰj-1���ַ������������
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
