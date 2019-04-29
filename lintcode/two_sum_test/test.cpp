// Copyright 2018.刘珅珅
// author：刘珅珅
// 两数之和
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
			// target - numbers[i]在hash存在的更早
            // hash值为下标，所以其下标更小
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
