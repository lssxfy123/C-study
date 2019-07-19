// Copyright 2019.刘珅珅
// author：刘珅珅
// 数据流中位数
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<int> medianII(vector<int> &nums) {
	// write your code here
	vector<int> result;
	if (nums.size() == 0)
	{
		return result;
	}

	vector<int> tmp;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (tmp.empty())
		{
			tmp.push_back(nums[i]);
		}
		else if (tmp.back() <= nums[i])
		{
			tmp.push_back(nums[i]);
		}
		else
		{
			// 通过二分法查找tmp中第一个比nums[i]大的元素
			// tmp就形成了排序数组
			int start = 0;
			int end = tmp.size() - 1;
			int insert_index = -1;
			while (start + 1 < end)
			{
				int middle = start + (end - start) / 2;
				if (tmp[middle] < nums[i])
				{
					start = middle + 1;
				}
				else if (tmp[middle] > nums[i])
				{
					end = middle - 1;
				}
				else
				{
					insert_index = middle;
					break;
				}
			}

			if (insert_index < 0)
			{
				if (tmp[start] > nums[i])
				{
					insert_index = start;
				}
				else if (tmp[end] >= nums[i])
				{
					insert_index = end;
				}
				else
				{
					insert_index = end + 1;
				}
			}

			if (insert_index >= 0)
			{
				tmp.insert(tmp.begin() + insert_index, nums[i]);
			}
		}
		result.push_back(tmp[(tmp.size() - 1) / 2]);
	}

	return result;
}

int main(int argc, char* argv[])
{
	vector<int> vec{ 1, 2, 3, 4, 5 };
	//vec.insert(vec.begin() + 1, 99);
	//PrintElements(vec);
	PrintElements(medianII(vec));
	vector<int> vec1{ 4, 5, 1, 3, 2, 6, 0 };
	PrintElements(medianII(vec1));
	return 0;
}
