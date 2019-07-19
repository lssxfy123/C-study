// Copyright 2019.刘珅珅
// author：刘珅珅
// 落单的数 III
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<int> singleNumberIII(vector<int> &A) {
	// write your code here
	vector<int> result;
	if (A.size() <= 2)
	{
		return A;
	}

	int tmp = 0;
	// 假设单独的两个数分别为a和b
	// xor运算两个相同数的xor为0
	// 某个数与0进行xor结果为其自身
	// 则tmp=a xor b
	for (int i = 0; i < A.size(); ++i)
	{
		tmp ^= A[i];
	}

	int a = 0;
	int b = 0;

	// tmp二进制位中必然有为1的位，否则a=b
	// 并且a和b在该位上的值肯定不同，一个为1，一个为0
	// 找出tmp二进制是1的最低位
	// 两个相邻数进行&，得到的是较大数去掉最低位的1
	// 例：6 & 5得到是0110，去掉最低位1即0100为4
	// 6-4为2即是6的最低位0010
	// 根据tmp将A分为两部分，一部分是在tmp为1的二进制位上也是1
	// 另一部分是在tmp为1的二进制位上是0
	// 这样a分在某一部分，b分在另一部分
	// 两部分分别进行xor运算，得到a和b
	tmp = tmp - (tmp & (tmp - 1));
	for (int i = 0; i < A.size(); ++i)
	{
		// tmp二进制只有1位是1
		// (A[i] & tmp)==0表示该数在tmp为1的二进制位上是0
		if ((A[i] & tmp) == 0) 
		{
			a ^= A[i];
		}
		else
		{
			b ^= A[i];
		}
	}

	result.push_back(a);
	result.push_back(b);
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 1, 2, 2, 3 ,4, 4, 5, 3 };
	PrintElements(singleNumberIII(vec));
	return 0;
}
