// Copyright 2019.���|�|
// author�����|�|
// �������
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../include/print.hpp"

vector<pair<int, double>> dicesSumTest(int n) {
    // Write your code here
    vector<pair<int, double>> results;
    if (n <= 0)
    {
        pair<int, double> p(0, 0.0);
        results.push_back(p);
        return results;
    }

    vector<vector<long long>> dp;
    for (int i = 0; i <= n; ++i)
    {
        vector<long long> sum(6 * n + 1, 0);
        dp.push_back(sum);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            for (int j = 1; j <= 6; ++j)
            {
                dp[i][j] = 1;
            }
            continue;
        }

        for (int j = i; j <= 6 * i; ++j)
        {
            if (j - 1 > 0)
            {
                dp[i][j] += dp[i - 1][j - 1];
            }

            if (j - 2 > 0)
            {
                dp[i][j] += dp[i - 1][j - 2];
            }

            if (j - 3 > 0)
            {
                dp[i][j] += dp[i - 1][j - 3];
            }

            if (j - 4 > 0)
            {
                dp[i][j] += dp[i - 1][j - 4];
            }

            if (j - 5 > 0)
            {
                dp[i][j] += dp[i - 1][j - 5];
            }

            if (j - 6 > 0)
            {
                dp[i][j] += dp[i - 1][j - 6];
            }
        }
    }

    return results;
}

vector<pair<int, double>> dicesSum(int n) {
    // Write your code here
    vector<pair<int, double>> results;
    if (n <= 0)
    {
        pair<int, double> p(0, 0.0);
        results.push_back(p);
        return results;
    }

    // ����һ����ά���飬����Ϊ������n����Ϊn�����ӺͿ��ܵ�ȡֵSum
    // ����Ԫ��Ϊȡ����ӦSum�Ĵ���
    // ����n�����ӣ������ΪSum����n-1������������6�����
    // (n-1, Sum-1)����n�������ӳ�1 Sum-1>0
    // (n-1, Sum-2)����n�������ӳ�2 Sum-2>0
    // (n-1, Sum-3)����n�������ӳ�3 Sum-3>0
    // (n-1, Sum-4)����n�������ӳ�4 Sum-4>0
    // (n-1, Sum-5)����n�������ӳ�5 Sum-5>0
    // (n-1, Sum-6)����n�������ӳ�6 Sum-6>0
    /*
    Sum 1 2 3 4 5 6 7 8 9 10 11 12
    n=1   1 1 1 1 1 1 0 0 0 0  0   0
    n=2   0 1 2 3 4 5 6 5 4 3  2   1
    */

    // n�����ӣ������������Ϊn����Ϊ6n
    // ����dpʱ�������1��1�У����ں���������
    // �������������������������������ǿ��ܵ�Sum
    // ��ʵ�ʼ���ʱ�������е�Ԫ�ز���ȡ���ܳ���Sum�Ĵ���
    // ��Ϊ�����ǳ����п��ܻ����Խ�������������и���
    // dicesSumTest����n=15����Ͳ���ȷ�ˣ�����dp��ֱ�Ӵ洢����
    vector<vector<double>> dp;
    for (int i = 0; i <= n; ++i)
    {
        vector<double> sum(6 * n + 1, 0);
        dp.push_back(sum);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            for (int j = 1; j <= 6; ++j)
            {
                dp[i][j] = 1 / 6.0;
            }
            continue;
        }

        // �����������ʵļ��㹫ʽP(A) = P(A|B)*P(B)
        // dp[i][j]��ʾi�����Ӻ�Ϊj�ĸ��ʣ�
        // dp[i-1][j-1]��ʾi-1�����Ӻ�Ϊj-1�ĸ���,
        // ��i�������ӳ�1,2,3,4,5,6�ĸ��ʶ�Ϊ1/6
        // dp[i][j] = dp[i-1][j-1] * 1/6 + dp[i-1][j-2] * 1/6
        // + dp[i-1][j-3] * 1/6 + dp[i-1][j-4] * 1/6 + dp[i-1][j-5] * 1/6
        // + dp[i-1][j-6] * 1/6
        for (int j = i; j <= 6 * i; ++j)
        {
            if (j - 1 > 0)
            {
                dp[i][j] += dp[i - 1][j - 1] / 6.0;
            }

            if (j - 2 > 0)
            {
                dp[i][j] += dp[i - 1][j - 2] / 6.0;
            }

            if (j - 3 > 0)
            {
                dp[i][j] += dp[i - 1][j - 3] / 6.0;
            }

            if (j - 4 > 0)
            {
                dp[i][j] += dp[i - 1][j - 4] / 6.0;
            }

            if (j - 5 > 0)
            {
                dp[i][j] += dp[i - 1][j - 5] / 6.0;
            }

            if (j - 6 > 0)
            {
                dp[i][j] += dp[i - 1][j - 6] / 6.0;
            }
        }
    }

    return results;
}

int main(int argc, char* argv[])
{
    dicesSum(15);
    return 0;
}
