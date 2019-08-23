// Copyright 2019.刘珅珅
// author：刘珅珅
// 背包问题II
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;


class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @param V: Given n items with value V[i]
	 * @return: The maximum value
	 */
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int n = A.size();
		if (n == 0 || m == 0)
		{
			return 0;
		}

		// 降维处理
		vector<int> dp(m + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = m; j >= A[i]; --j)
			{
				dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
			}
		}
		return dp[m];
	}

	int backPackII2(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int n = A.size();
		if (n == 0 || m == 0)
		{
			return 0;
		}

		// dp[i-1][j-1]表示前i个物品放在大小为j的背包中可获取的最大价值
		// 状态转移方程为：dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i]]+V[i])
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (j < A[i - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					// dp[i-1][j]表示不选第i个物品的重量为j的背包的价值
					// dp[i-1][j-A[i-1]]+V[i]表示选第i个物品，则背包重量j要剔除掉
					// 第i个物品的重量A[i-1]，然后加上第i个物品的价值V[i]
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i -1]] + V[i - 1]);
				}
			}
		}
		return dp[n][m];
	}

};

int main(int argc, char* argv[])
{
	int m = 100;
	vector<int> A{ 77, 22, 29, 50, 90 };
	vector<int> V{ 92, 22, 87, 46, 90 };
	Solution s;
	cout << s.backPackII2(m, A, V) << endl;
	return 0;
}
