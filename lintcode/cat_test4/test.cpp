// Copyright 2019.刘珅珅
// author：刘珅珅
// 463. 整数排序
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

void sortIntegers(vector<int> &A) {
	// write your code here
	int j = 0;
	for (int i = 1; i < A.size(); ++i)
	{
		// 必须使用一个临时变量
		// 内层的for循环有可能会会改变A[i]
		int tmp = A[i];
		for (j = i; j > 0 && A[i] < A[j - 1]; --j)
		{
			A[j] = A[j - 1];
		}
		A[j] = tmp;  // 不能写成A[j]=A[i],A[i]在内层的for循环会被改变
	}
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 3,2,1,4,5 };
	sortIntegers(vec);
	PrintElements(vec);
	return 0;
}
