// Copyright 2019.���|�|
// author�����|�|
// ��������II
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

		// ��ά����
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

		// dp[i-1][j-1]��ʾǰi����Ʒ���ڴ�СΪj�ı����пɻ�ȡ������ֵ
		// ״̬ת�Ʒ���Ϊ��dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i]]+V[i])
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
					// dp[i-1][j]��ʾ��ѡ��i����Ʒ������Ϊj�ı����ļ�ֵ
					// dp[i-1][j-A[i-1]]+V[i]��ʾѡ��i����Ʒ���򱳰�����jҪ�޳���
					// ��i����Ʒ������A[i-1]��Ȼ����ϵ�i����Ʒ�ļ�ֵV[i]
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
