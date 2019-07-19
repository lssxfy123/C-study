// Copyright 2019.���|�|
// author�����|�|
// ������Ӵ�
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

	// dp[i][j]��ʾA��ǰi���ַ���B��ǰj���ַ��Ե�i���ַ��͵�j���ַ���β�Ĺ����Ӵ��ĳ���
	// �����i���ַ������ڵ�j���ַ�����dp[i][j]=0
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	result = dp[0][0];
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			// �����Ӵ�������������
			// һ����ƥ��dp[i][j]Ϊ0
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
