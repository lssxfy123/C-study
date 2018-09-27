// Copyright 2018.刘珅珅
// author：刘珅珅
// 两数之和
#include <algorithm>
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
	sort(numbers.begin(), numbers.end());
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> numbers{ 7, 2, 13, 9 };
	twoSum(numbers, 9);
	return 0;
}
