// Copyright 2019.刘珅珅
// author：刘珅珅
// 骰子求和
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

    // 构造一个二维数组，行数为骰子数n，列为n个骰子和可能的取值Sum
    // 数组元素为取到对应Sum的次数
    // 对于n个骰子，如果和为Sum，则n-1个骰子有下面6种情况
    // (n-1, Sum-1)：第n个骰子扔出1 Sum-1>0
    // (n-1, Sum-2)：第n个骰子扔出2 Sum-2>0
    // (n-1, Sum-3)：第n个骰子扔出3 Sum-3>0
    // (n-1, Sum-4)：第n个骰子扔出4 Sum-4>0
    // (n-1, Sum-5)：第n个骰子扔出5 Sum-5>0
    // (n-1, Sum-6)：第n个骰子扔出6 Sum-6>0
    /*
    Sum 1 2 3 4 5 6 7 8 9 10 11 12
    n=1   1 1 1 1 1 1 0 0 0 0  0   0
    n=2   0 1 2 3 4 5 6 5 4 3  2   1
    */

    // n个骰子，上述矩阵的行为n，列为6n
    // 分配dp时，多分配1行1列，便于后面计算理解
    // 这样行索引就是骰子数，列索引就是可能的Sum
    // 在实际计算时，矩阵中的元素不能取可能出现Sum的次数
    // 因为次数非常大，有可能会出现越界的情况，测试中根据
    // dicesSumTest函数n=15结果就不正确了，所以dp中直接存储概率
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

        // 根据条件概率的计算公式P(A) = P(A|B)*P(B)
        // dp[i][j]表示i个骰子和为j的概率，
        // dp[i-1][j-1]表示i-1个骰子和为j-1的概率,
        // 第i个骰子扔出1,2,3,4,5,6的概率都为1/6
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
