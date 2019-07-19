// Copyright 2019.���|�|
// author�����|�|
// �䵥���� III
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
	// ���赥�����������ֱ�Ϊa��b
	// xor����������ͬ����xorΪ0
	// ĳ������0����xor���Ϊ������
	// ��tmp=a xor b
	for (int i = 0; i < A.size(); ++i)
	{
		tmp ^= A[i];
	}

	int a = 0;
	int b = 0;

	// tmp������λ�б�Ȼ��Ϊ1��λ������a=b
	// ����a��b�ڸ�λ�ϵ�ֵ�϶���ͬ��һ��Ϊ1��һ��Ϊ0
	// �ҳ�tmp��������1�����λ
	// ��������������&���õ����ǽϴ���ȥ�����λ��1
	// ����6 & 5�õ���0110��ȥ�����λ1��0100Ϊ4
	// 6-4Ϊ2����6�����λ0010
	// ����tmp��A��Ϊ�����֣�һ��������tmpΪ1�Ķ�����λ��Ҳ��1
	// ��һ��������tmpΪ1�Ķ�����λ����0
	// ����a����ĳһ���֣�b������һ����
	// �����ֱַ����xor���㣬�õ�a��b
	tmp = tmp - (tmp & (tmp - 1));
	for (int i = 0; i < A.size(); ++i)
	{
		// tmp������ֻ��1λ��1
		// (A[i] & tmp)==0��ʾ������tmpΪ1�Ķ�����λ����0
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
