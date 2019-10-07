// Copyright 2019.刘珅珅
// author：刘珅珅
// 换硬币
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

		// 状态转移方程：dp[i][j]=min(dp[i-1][j],dp[i-1][j-k*coins[i]]+k)  (0≤k*coins[i]≤j)
		// 降维后：dp[j]=min(dp[j],dp[j-k*coins[i]]+k)  (0≤k*coins[i]≤j)
		// dp[j-1]表示总金额为j时的最少硬币个数
		// 初始化默认为-1，表示如果无法组合出金额j
		// 则dp[j-1]为-1
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j <= amount; ++j)
			{
				// 如果总金额j大于等于第i个硬币的面额
				// 并且j-coins[i]的硬币数不为-1
				// 即必须有硬币能够组合成j-coins[i]
				// 表示如果无法组合出来j-coins[i]，就不能
				// 选用coins[i]
				if (coins[i] <= j && dp[j - coins[i]] != -1)
				{
					// dp[j]==-1表示之前没有组合出总金额-1
					// dp[j-coins[i]]+1< dp[j]表示之前有硬币
					// 组合出j，选用coins[i]后并且只选用1个coins[i]后的
					// 硬币数dp[j-coins[i]]+1小于dp[j]
					// 对比状态转移方程k=1，因为要求硬币数最少
					// 不会出现k>1，反而硬币数少的情况
					// 例如k=2，如果dp[j-2*coins[i]]+2<dp[j-coins[i]]+1
					// 则dp[j-2*coins[i]]+1<dp[j-coins[i]]
					// 由于j-2*coins[i]<j-coins[i]，内层的for循环就会进行替换
					// 即dp[j-coins[i]]=dp[j-2*coins[i]]+1
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
