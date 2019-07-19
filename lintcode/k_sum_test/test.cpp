// Copyright 2019.���|�|
// author�����|�|
// K��֮��
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int kSum(vector<int> &A, int k, int target) {
	// write your code here
	int result = 0;

	// A��ȫΪ������
	if (A.size() < k || target <= 0 || k <= 0)
	{
		return result;
	}

	// ��ʹ���ַ�����k��������ͬ�ģ�ֻҪ�������е�λ�ò���ȫ��ͬ��Ҳ�ǲ�ͬ�ķ���
	// ����һ����ά���飬����dp[i][j][m]��ʾǰi������ȡj������Ϊm�ķ�������ת�Ʒ���Ϊ
	// dp[i][j][m] = dp[i-1][j][m]+dp[i-1][j-1][m-A[i]]��dp[i-1][j][m]��ʾǰi-1������ȡj������Ϊm
	// ����ʹ��A[i]��dp[i-1][j-1][m-A[i]]��ʾǰi-1������ȡj-1������Ϊm-A[i]������Ҫʹ��A[i]
	// ��ת�Ʒ��̿��Կ���iֻ��i-1��أ�����dp����ȥ��һά
	vector<vector<int>> dp(k + 1, vector<int>(target + 1, 0));
	dp[0][0] = 1;

	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = k; j >= 1; --j)
		{
			// ��ΪA�е��������ֶ���������
			// j���Ǵ�target��num�е�����������
			// ���ÿ���Խ������⣬���ǿ����
			for (int m = target; m >= A[i]; --m)
			{
				// =�ұߵ�dp[j][m]��ʾA[i]֮ǰ������ȡj������Ϊm������ʹ��A[i]
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
