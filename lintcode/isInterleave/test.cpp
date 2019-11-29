// Copyright 2019.���|�|
// author�����|�|
// �����ַ���
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

    // ʹ�ö�̬�滮��⣬dp[i][j]��ʾs3
    // ��ǰi+jλ�Ƿ���s1��ǰiλ��s2��ǰjλ�������(��ʹdp[i][j]ΪfalseҲ������s3�Ͳ�����s1��s2���湹��)
    // ��ά���ݶ����һ��һ�У����ڴ洢s3ֻƥ��s1��s3ֻƥ��s2
    vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));

    // ����s1��s2��Ϊ���ַ���,s3ҲΪ��(�����Ϊ�գ�֮ǰ�ͻ᷵��false)������Ϊtrue
    dp[0][0] = true;

    // ֻƥ��s3��s1
    for (int i = 1; i <= s1.length(); ++i)
    {
        dp[i][0] = dp[i - 1][0] && s3[i - 1] == s1[i - 1];
    }

    // ֻƥ��s3��s2
    for (int j = 1; j <= s2.length(); ++j)
    {
        dp[0][j] = dp[0][j - 1] && s3[j - 1] == s2[j - 1];
    }

    for (int i = 1; i <= s1.length(); ++i)
    {
        for (int j = 1; j <= s2.length(); ++j)
        {
            // s3�����s1��s2���湹�ɣ�ֻ�������ߺ��������������
            // �����ߣ�ȡs1��ֵ
            if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
            {
                dp[i][j] = true;
            }
            // �����ߣ�ȡs2��ֵ
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
