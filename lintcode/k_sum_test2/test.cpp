// Copyright 2019.刘珅珅
// author：刘珅珅
// k数和 II
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// 深度优先搜索
void dfs(vector<int>& A, int k, int target, int index, vector<vector<int>>& result, vector<int> tmp)
{
	if (k == 0 && target == 0)
	{
		result.push_back(tmp);
		tmp.clear();
		return;
	}

	if (k < 0 || target < 0 || index >= A.size())
	{
		return;
	}

	tmp.push_back(A[index]);
	dfs(A, k - 1, target - A[index], index + 1, result, tmp);  // 选择A[index]

	tmp.pop_back();
	dfs(A, k, target, index + 1, result, tmp);  // 不选择A[index]
}


vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
	// write your code here
	vector<vector<int>> result;
	if (A.size() < k || k <= 0 || target <= 0)
	{
		return result;
	}

	vector<int> tmp;
	dfs(A, k, target, 0, result, tmp);
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 1, 2, 3, 4 };
	auto result = kSumII(vec, 2, 5);
	return 0;
}
