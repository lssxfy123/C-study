// Copyright 2019.���|�|
// author�����|�|
// ��k��Ԫ��
// ��ע��ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
// ʹ�ÿ��ٲ���
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// ��������
// ���鳤�ȱȽ�Сʱʹ�ò�������
// ֻ�������һ����
void InsertionSort(vector<int>& nums, int left, int right)
{
	int j;
	for (int i = left + 1; i <= right; ++i)
	{
		int temp = nums[i];
		// ��i��Ԫ����֮ǰ��0-i - 1���бȽ�
		for (j = i; j > 0 && temp > nums[j - 1]; --j)
		{
			// �ƶ�����
			// ���temp<array[j - 1]����array[j - 1]����ƶ�
			// �Ա����temp
			nums[j] = nums[j - 1];
		}
		nums[j] = temp;
	}
}

// ������ŦԪ
int Median3(vector<int>& nums, int left, int right)
{
	int center = (left + right) / 2;
	if (nums[center] > nums[left])
	{
		swap(nums[left], nums[center]);
	}

	if (nums[right] > nums[left])
	{
		swap(nums[left], nums[right]);
	}

	if (nums[right] > nums[center])
	{
		swap(nums[right], nums[center]);
	}

	// array[left] > array[center] > array[right]
	// �����ٱȽ�һ��
	swap(nums[center], nums[left + 1]);
	return nums[left + 1];
}

// ���ٲ��ң����ҵ�k�����ֵ
// ע����sort_test4���ҵ�k����Сֵ�Ƚ�
void QuickSelect(vector<int>& nums, int left, int right, int k)
{
	if (left + 10 <= right)
	{
		int pivot = Median3(nums, left, right);
		int i = left + 1;  // nums[left]�϶� > pviot
		int j = right;  
		for (; ;)
		{
			while (nums[++i] > pivot)
			{
			}

			while (pivot > nums[--j])
			{
			}

			if (i < j)
			{
				swap(nums[i], nums[j]);
			}
			else
			{
				break;
			}
		}

		// nums[left + 1]�洢����pivot
		// ����֮��nums[j]�洢����pivot
		swap(nums[j], nums[left + 1]);

		if (k <= j)
		{
			// ֻ��left��j - 1��Ԫ��
			QuickSelect(nums, left, j - 1, k);
		}
		else
		{
			QuickSelect(nums, j + 1, right, k);
		}
	}
	else
	{
		InsertionSort(nums, left, right);
	}
}

int kthLargestElement(int n, vector<int> &nums) {
	// write your code here
	if (nums.size() == 0 || n <= 0 || n > nums.size())
	{
		return -1;
	}

	QuickSelect(nums, 0, nums.size() - 1, n);
	return nums[n - 1];
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 1, 3, 4, 2 };
	vector<int> vec1{ 1,3,4,2, 5, 7, 8, 9, 10, 12, 23, 45, 15, 18, 19, 78, 21, 34, 2, 4, 5, 67, 82 };
	vector<int> vec2{ 1,3,4,2, 5, 7, 8, 9, 10, 12, 23, 45, 15, 18, 19, 78, 21, 34, 2, 4, 2 };
	int k = 1;
	//cout << kthLargestElement(k, vec) << endl;

	k = 4;
	cout << kthLargestElement(k, vec1) << endl;
	cout << kthLargestElement(k, vec2) << endl;
	return 0;
}
