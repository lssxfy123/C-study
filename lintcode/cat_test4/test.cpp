// Copyright 2019.���|�|
// author�����|�|
// 463. ��������
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
		// ����ʹ��һ����ʱ����
		// �ڲ��forѭ���п��ܻ��ı�A[i]
		int tmp = A[i];
		for (j = i; j > 0 && A[i] < A[j - 1]; --j)
		{
			A[j] = A[j - 1];
		}
		A[j] = tmp;  // ����д��A[j]=A[i],A[i]���ڲ��forѭ���ᱻ�ı�
	}
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 3,2,1,4,5 };
	sortIntegers(vec);
	PrintElements(vec);
	return 0;
}
