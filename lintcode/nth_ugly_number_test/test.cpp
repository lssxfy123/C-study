// Copyright 2019.刘珅珅
// author：刘珅珅
// 第n个丑数
// 备注：O(nlogn)或O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../include/print.hpp"
using namespace std;

int nthUglyNumber(int n) {
	// write your code here
	if (n <= 5)
	{
		return n;
	}
	
	vector<int> result;
	result.push_back(1);  // 第1个丑数
	int index_2 = 0; 
	int index_3 = 0; 
	int index_5 = 0;

	// 丑数为某个丑数与2，3，5的乘积
	// 第二个丑数应该是： min(result[0] * 2, result[0] * 3, result[0] * 5); min(2, 3, 5) = 2
	// 第三个丑数应该是： min(result[1] * 2, result[0] * 3, result[0] * 5); min(4, 3, 5) = 3
	// 第三个丑数应该是： min(result[1] * 2, result[1] * 3, result[0] * 5); min(4, 6, 5) = 4
	// 每次更新只更新一个数，了保证这样更新的数一定是有序的
	// 2，3，5这三个因子保持不动，哪一个因子作用的数被采纳，我们就把对应的索引 + 1，
	// 这样虽然会有重复计算，但是可以保证每次更新的都是最小的丑数。
	// 如果一个循环中算出了两个最小值，
	// 那么对应的两个索引都++
	for (int i = 1; i < n; ++i)
	{
		int two = 2 * result[index_2];
		int three = 3 * result[index_3];
		int five = 5 * result[index_5];
		result.push_back(min(min(two, three), five));
		if (two == result.back())
		{
			++index_2;
		}

		if (three == result.back())
		{
			++index_3;
		}

		if (five == result.back())
		{
			++index_5;
		}
	}

	return result.back();
}

int main(int argc, char* argv[])
{
	cout << nthUglyNumber(1000) << endl;
	return 0;
}
