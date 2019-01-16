// Copyright 2019.刘珅珅
// author：刘珅珅
// 子数组和为0
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../include/print.hpp"
using namespace std;

vector<int> subarraySum(vector<int> &nums) {
	// write your code here
	vector<int> result;
	if (nums.size() == 0)
	{
		return result;
	}

	// sum_map的key为数组元素累加的和
	// value为对应的元素索引
	unordered_map<int, int> sum_map;
	int sum = 0;

	// 初始化一个key=0的值
	// 是为了数组累加和为0的情况
	sum_map[0] = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		// 寻找子数组和为0的思路：sum为元素从开始
		// 累加的结果，如果发现sum已经存在，则从上个
		// sum到这个sum直接的子数组的和一定为0，例如sum=2,
		// 再次出现sum=2则表示，之间的子数组的和一定为0
		if (sum_map.find(sum) != sum_map.end())
		{
			result.push_back(sum_map[sum] + 1);
			result.push_back(i);
			return result;
		}
		sum_map[sum] = i;
	}

	return result;
}

int main(int argc, char* argv[])
{
	vector<int> vec{ -3, 1, 2, -3, 4 };
	vector<int> result = subarraySum(vec);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
