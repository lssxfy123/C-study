// Copyright 2019.���|�|
// author�����|�|
// ��������
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int backPack(int m, vector<int> &A) {
    // write your code here
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }

    // dp[i][j]��ʾǰi����Ʒ������Ϊj�ı���������ܷ��������
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j >= A[i - 1])
            {
                // ������ѡ���i����Ʒ��ѡ���i����Ʒ
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

// ��ά����
int backPack1(int m, vector<int> &A) {
    // write your code here
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }

    // dp[j]��ʾ����Ϊj�ı���������ܷ��������
    // ��backPack�����п��Կ�����̬�滮��״̬ת�Ʒ���
    // ��1��ά��iֻ��i-1��أ����Կ��Խ�ά
    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j >= A[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
        }
    }
    return dp[m];
}


int main(int argc, char* argv[])
{
    vector<int> vec{ 3, 4, 8, 5 };
    cout << backPack1(10, vec) << endl;
    vector<int> vec1{2, 3, 5, 7};
    cout << backPack1(12, vec1) << endl;
    return 0;
}
