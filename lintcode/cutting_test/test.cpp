// Copyright 2019.���|�|
// author�����|�|
// ���ӷָ�
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
	/**
	 * @param prices: the prices
	 * @param n: the length of rod
	 * @return: the max value
	 */
	int cutting(vector<int> &prices, int n) {
		// Write your code here
		int m = prices.size();
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (j > i)
				{
					// ѡ���i��Ԫ�غͲ�ѡ���i��Ԫ��
					// ��i��Ԫ�صĳ���Ϊi+1������Ϊdp[j-i-1]
					dp[j] = max(dp[j], dp[j - i - 1] + prices[i]);
				}
			}
		}
		return dp[n];
	}
};

int main(int argc, char* argv[])
{
	vector<int> prices{ 1, 5, 8, 9, 10, 17, 17, 20 };
	Solution s;
	cout << s.cutting(prices, 8) << endl;

	vector<int> prices1{ 3, 5, 8, 9, 10, 17, 17, 20 };
	cout << s.cutting(prices1, 8) << endl;
	return 0;
}
