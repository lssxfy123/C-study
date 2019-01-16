// Copyright 2019.���|�|
// author�����|�|
// ��n������
// ��ע��O(nlogn)��O(n)
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
	result.push_back(1);  // ��1������
	int index_2 = 0; 
	int index_3 = 0; 
	int index_5 = 0;

	// ����Ϊĳ��������2��3��5�ĳ˻�
	// �ڶ�������Ӧ���ǣ� min(result[0] * 2, result[0] * 3, result[0] * 5); min(2, 3, 5) = 2
	// ����������Ӧ���ǣ� min(result[1] * 2, result[0] * 3, result[0] * 5); min(4, 3, 5) = 3
	// ����������Ӧ���ǣ� min(result[1] * 2, result[1] * 3, result[0] * 5); min(4, 6, 5) = 4
	// ÿ�θ���ֻ����һ�������˱�֤�������µ���һ���������
	// 2��3��5���������ӱ��ֲ�������һ���������õ��������ɣ����ǾͰѶ�Ӧ������ + 1��
	// ������Ȼ�����ظ����㣬���ǿ��Ա�֤ÿ�θ��µĶ�����С�ĳ�����
	// ���һ��ѭ���������������Сֵ��
	// ��ô��Ӧ������������++
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
