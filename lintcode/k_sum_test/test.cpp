// Copyright 2019.刘珅珅
// author：刘珅珅
// K数之和
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int kSum(vector<int> &A, int k, int target) {
	// write your code here
	int result = 0;

	// A中全为正整数
	if (A.size() < k || target <= 0 || k <= 0)
	{
		return result;
	}

	// 即使两种方案中k个数是相同的，只要在数组中的位置不完全相同，也是不同的方案
	// 建立一个三维数组，其中dp[i][j][m]表示前i个数里取j个数和为m的方案数，转移方程为
	// dp[i][j][m] = dp[i-1][j][m]+dp[i-1][j-1][m-A[i]]，dp[i-1][j][m]表示前i-1个数里取j个数和为m
	// 即不使用A[i]，dp[i-1][j-1][m-A[i]]表示前i-1个数里取j-1个数和为m-A[i]，即需要使用A[i]
	// 从转移方程可以看出i只和i-1相关，所以dp可以去掉一维
	vector<vector<int>> dp(k + 1, vector<int>(target + 1, 0));
	dp[0][0] = 1;

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = k; j >= 1; --j)
		{
			// 因为A中的所有数字都是正整数
			// j就是从target到num中的所有正整数
			// 不用考虑越界的问题，不是考察点
			for (int m = target; m >= A[i]; --m)
			{
				// =右边的dp[j][m]表示A[i]之前的数组取j个数和为m，即不使用A[i]
				dp[j][m] = dp[j][m] + dp[j - 1][m - A[i]];
			}
		}
	}

	result = dp[k][target];
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 1, 2, 3, 4 };
	cout << kSum(vec, 2, 5) << endl;
	return 0;
}
