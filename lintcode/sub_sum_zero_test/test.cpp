// Copyright 2019.���|�|
// author�����|�|
// �������Ϊ0
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

	// sum_map��keyΪ����Ԫ���ۼӵĺ�
	// valueΪ��Ӧ��Ԫ������
	unordered_map<int, int> sum_map;
	int sum = 0;

	// ��ʼ��һ��key=0��ֵ
	// ��Ϊ�������ۼӺ�Ϊ0�����
	sum_map[0] = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		// Ѱ���������Ϊ0��˼·��sumΪԪ�شӿ�ʼ
		// �ۼӵĽ�����������sum�Ѿ����ڣ�����ϸ�
		// sum�����sumֱ�ӵ�������ĺ�һ��Ϊ0������sum=2,
		// �ٴγ���sum=2���ʾ��֮���������ĺ�һ��Ϊ0
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
