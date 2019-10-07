// Copyright 2019.���|�|
// author�����|�|
// �༭����
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param word1: A string
    * @param word2: A string
    * @return: The minimum number of steps.
    */
    int minDistance(string &word1, string &word2) {
        // write your code here
        int row = word1.length() + 1;
        int col = word2.length() + 1;

        // dp[i][j]��ʾword1��ǰi���ַ�ת��Ϊword2��ǰj���ַ���Ҫ����С����
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // word1ת��Ϊword2��ǰ0���ַ�
        // ��ת��Ϊ���ַ�����
        // ȫ��Ϊɾ������dp[i][0]=i
        for (int i = 0; i < row; ++i)
        {
            dp[i][0] = i;
        }

        // ���ַ�ת��Ϊword2��ǰj���ַ�
        // ȫ��Ϊ�������dp[0][j]=j
        for (int j = 0; j < col; ++j)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                // ����һ��״̬ת����dp[i][j]�ܹ���3�ֲ���
                // 1. ��ӣ���word1ǰi���ַ�����һ����word2ǰj���ַ�
                // �����һ���ַ���ͬ���ַ�,�����������Ϊ1��
                // ��dp[i][j]=dp[i][j-1]+1
                // ������ab-->cd�����Լ����ab-->c�Ĵ���(��dp[i][j-1])��Ȼ���ٲ���d
                // 2. ɾ����ɾ��word1ǰi���ַ������һ���ַ���Ȼ���ǰi-1���ַ�ת��Ϊ
                // word2��ǰj���ַ�����dp[i][j]=dp[i-1][j]+1
                // ������ab-->cd�������a-->cd�Ĵ�������ɾ��b
                // 3. �滻����word1ǰi���ַ������һ���ַ��滻Ϊword2ǰj���ַ������һ���ַ�
                // �����Ϊ������������word1[i-1]==word2[j-1]������Ҫ�滻����dp[i][j]=dp[i-1][j-1]
                // ��������,��dp[i][j]=dp[i-1][j-1]+1
                // ���ȡ��3���������С����
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            }
        }
        return dp[row - 1][col - 1];
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
