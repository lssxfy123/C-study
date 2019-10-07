// Copyright 2019.���|�|
// author�����|�|
// ��Ӳ��
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
	/**
	 * @param coins: a list of integer
	 * @param amount: a total amount of money amount
	 * @return: the fewest number of coins that you need to make up
	 */
	int coinChange(vector<int> &coins, int amount) {
		// write your code here
		int n = coins.size();
		if (n == 0 || amount == 0)
		{
			return 0;
		}

		// ״̬ת�Ʒ��̣�dp[i][j]=min(dp[i-1][j],dp[i-1][j-k*coins[i]]+k)  (0��k*coins[i]��j)
		// ��ά��dp[j]=min(dp[j],dp[j-k*coins[i]]+k)  (0��k*coins[i]��j)
		// dp[j-1]��ʾ�ܽ��Ϊjʱ������Ӳ�Ҹ���
		// ��ʼ��Ĭ��Ϊ-1����ʾ����޷���ϳ����j
		// ��dp[j-1]Ϊ-1
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				// ����ܽ��j���ڵ��ڵ�i��Ӳ�ҵ����
				// ����j-coins[i]��Ӳ������Ϊ-1
				// ��������Ӳ���ܹ���ϳ�j-coins[i]
				// ��ʾ����޷���ϳ���j-coins[i]���Ͳ���
				// ѡ��coins[i]
				if (coins[i] <= j && dp[j - coins[i]] != -1)
				{
					// dp[j]==-1��ʾ֮ǰû����ϳ��ܽ��-1
					// dp[j-coins[i]]+1< dp[j]��ʾ֮ǰ��Ӳ��
					// ��ϳ�j��ѡ��coins[i]����ֻѡ��1��coins[i]���
					// Ӳ����dp[j-coins[i]]+1С��dp[j]
					// �Ա�״̬ת�Ʒ���k=1����ΪҪ��Ӳ��������
					// �������k>1������Ӳ�����ٵ����
					// ����k=2�����dp[j-2*coins[i]]+2<dp[j-coins[i]]+1
					// ��dp[j-2*coins[i]]+1<dp[j-coins[i]]
					// ����j-2*coins[i]<j-coins[i]���ڲ��forѭ���ͻ�����滻
					// ��dp[j-coins[i]]=dp[j-2*coins[i]]+1
					if (dp[j] == -1 || dp[j - coins[i]] + 1 < dp[j])
					{
						dp[j] = dp[j - coins[i]] + 1;
					}
				}
			}
		}

		return dp[amount];
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<int> coins{9,9 };
	int amount = 0;
	cout << s.coinChange(coins, amount) << endl;
	return 0;
}
