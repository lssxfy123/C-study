// Copyright 2019.刘珅珅
// author：刘珅珅
// 最长公共子串
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int longestCommonSubstring(string &A, string &B) {
	// write your code here
	if (A.size() == 0 || B.size() == 0)
	{
		return 0;
	}

	int result = 0;
	int m = A.size();
	int n = B.size();

	// dp[i][j]表示A的前i个字符和B的前j个字符以第i个字符和第j个字符结尾的公共子串的长度
	// 如果第i个字符不等于第j个字符，则dp[i][j]=0
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	result = dp[0][0];
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			// 公共子串必须是连续的
			// 一旦不匹配dp[i][j]为0
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			if (dp[i][j] > result)
			{
				result = dp[i][j];
			}
		}
	}

	return result;
}

int main(int argc, char* argv[])
{
	string A = "ABCE";
	string B = "CBCE";
	cout << longestCommonSubstring(A, B) << endl;
	return 0;
}
