// Copyright 2019.刘珅珅
// author：刘珅珅
// 落单的数 II
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int singleNumberII(vector<int> &A) {
	// write your code here
	int result = 0;
	if (A.size() == 0)
	{
		return result;
	}

	int bits[32] = { 0 };

	for (int i = 0; i < 32; ++i)
	{
		for (int j = 0; j < A.size(); ++j)
		{
			// 统计A中所有数字的二进制表示中第i+1位是1个数
			// 例：i=0就表示所有数字二进制第1位是1的个数
			bits[i] += A[j] >> i & 0x00000001;
		}

		// 数组中如果数字出现3次，则其每个二进制位是1个个数也是3次
		// 对3进行取模运算，则bits[i]会有两种结果，为0或为1，为0表示那个
		// 单独的数在第i+1位不是1，为1表示其在第i+1位是1
		// 例：假设单独的数为1，则其二进制第1位为1，如果数组中存在其它二进制位第1位是1的数字
		// 由于其出现3次，最终统计的bits[0]=3*x+1，对3取模后为1。统计的bits[1]肯定是3*x，因为
		// 单独数字1的第2位是0，其它二进制第2位是1的数字都会出现3次
		bits[i] = bits[i] % 3;

		// bits[i]是0或1，将其左移i位，恢复其在单独数字原始的二进制位数
		// 最终的result就是单独数字
		result = result | bits[i] << i;
	}
	return result;
}

int main(int argc, char* argv[])
{
	vector<int> A{  1, 1, 2, 3, 3, 3, 2, 2, 4, 1 };
	cout << singleNumberII(A) << endl;
	return 0;
}
