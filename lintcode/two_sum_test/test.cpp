// Copyright 2018.���|�|
// author�����|�|
// ����֮��
#include <unordered_map>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
	// write your code 
	vector<int> result;
	if (numbers.size() < 2)
	{
		return result;
	}

	unordered_map<int, int> hash;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (hash.find(target - numbers[i]) != hash.end())
		{
			// target - numbers[i]��hash���ڵĸ���
            // hashֵΪ�±꣬�������±��С
			result.push_back(hash[target - numbers[i]]);
			result.push_back(i);
			return result;
		}
		hash[numbers[i]] = i;
	}
	result.push_back(-1);
	result.push_back(-1);
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> numbers{ 7, 2, 13, 9 };
	vector<int> result;
	result = twoSum(numbers, 9);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ",";
	}
	cout << endl;
	system("pause");
	return 0;
}
