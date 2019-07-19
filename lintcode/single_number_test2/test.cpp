// Copyright 2019.���|�|
// author�����|�|
// �䵥���� II
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
			// ͳ��A���������ֵĶ����Ʊ�ʾ�е�i+1λ��1����
			// ����i=0�ͱ�ʾ�������ֶ����Ƶ�1λ��1�ĸ���
			bits[i] += A[j] >> i & 0x00000001;
		}

		// ������������ֳ���3�Σ�����ÿ��������λ��1������Ҳ��3��
		// ��3����ȡģ���㣬��bits[i]�������ֽ����Ϊ0��Ϊ1��Ϊ0��ʾ�Ǹ�
		// ���������ڵ�i+1λ����1��Ϊ1��ʾ���ڵ�i+1λ��1
		// �������赥������Ϊ1����������Ƶ�1λΪ1����������д�������������λ��1λ��1������
		// ���������3�Σ�����ͳ�Ƶ�bits[0]=3*x+1����3ȡģ��Ϊ1��ͳ�Ƶ�bits[1]�϶���3*x����Ϊ
		// ��������1�ĵ�2λ��0�����������Ƶ�2λ��1�����ֶ������3��
		bits[i] = bits[i] % 3;

		// bits[i]��0��1����������iλ���ָ����ڵ�������ԭʼ�Ķ�����λ��
		// ���յ�result���ǵ�������
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
