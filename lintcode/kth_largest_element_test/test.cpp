// Copyright 2019.刘珅珅
// author：刘珅珅
// 第k大元素
// 备注：时间复杂度O(n) 空间复杂度O(1)
// 使用快速查找
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// 插入排序
// 数组长度比较小时使用插入排序
// 只排数组的一部分
void InsertionSort(vector<int>& nums, int left, int right)
{
	int j;
	for (int i = left + 1; i <= right; ++i)
	{
		int temp = nums[i];
		// 第i个元素与之前的0-i - 1进行比较
		for (j = i; j > 0 && temp > nums[j - 1]; --j)
		{
			// 移动数组
			// 如果temp<array[j - 1]，将array[j - 1]向后移动
			// 以便插入temp
			nums[j] = nums[j - 1];
		}
		nums[j] = temp;
	}
}

// 查找枢纽元
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
	// 后续少比较一次
	swap(nums[center], nums[left + 1]);
	return nums[left + 1];
}

// 快速查找，查找第k个最大值
// 注意与sort_test4查找第k个最小值比较
void QuickSelect(vector<int>& nums, int left, int right, int k)
{
	if (left + 10 <= right)
	{
		int pivot = Median3(nums, left, right);
		int i = left + 1;  // nums[left]肯定 > pviot
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

		// nums[left + 1]存储的是pivot
		// 交换之后，nums[j]存储的是pivot
		swap(nums[j], nums[left + 1]);

		if (k <= j)
		{
			// 只找left到j - 1的元素
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
