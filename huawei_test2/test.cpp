// Copyright 2019.刘珅珅
// author：刘珅珅
// 纯粹的快速排序
#include <iostream>
#include <vector>
using namespace std;

// 分区
int Partition(vector<int>& array, int left, int right)
{
	int pivot = array[left];
	int pivot_position = left;
	for (int i = left + 1; i <= right; ++i)
	{
		// 如果array[i]<pivot，则首先++pivot_position
		// pivot_position初始在最左边(默认没有元素小于pivot)，当array[i]<pivot时
		// 由于pivot_position需要满足:pivot_position左边元素比pivot小，右边比pivot大
		// 所以++pivot_position
		if (array[i] < pivot)
		{
			++pivot_position;
            // i肯定大于或等于pivot_position，其每个循环都会+1
			// ++pivot_position之后，如果i==pivot_position，则不需执行交换
            // 如果i!=pivot_position，则array[pivot_position]>=pivot
			// 否则执行++pivot_position之前将不满足右边的元素大于等于pivot的要求
			// 交换array[i]和array[pivot_position]，这样是为了将所有小于pivot的元素连续放置
			// 在循环结束后，只需交换array[left]和array[pivot_position]，pivot_position左边的元素
			// 肯定小于pivot，右边的大于等于pivot
			if (i != pivot_position)
			{
				swap(array[i], array[pivot_position]);
			}		
		}
	}

	if (left != pivot_position)
	{
		// 执行一次交换，枢纽元pivot原始在left位置
		// 根据上面for的比较规则，array[pivot_position]肯定小于pivot
		// 执行交换后，array[pivot_position]就是pivot
		swap(array[left], array[pivot_position]);
	}
	
	return pivot_position;
}

void QuickSort(vector<int>& array, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	// 找出一个分隔位置，left-pivot_position-1中的
	// 元素肯定比array[pivot_position]小，pivot_position+1-right
	// 肯定比array[pivot_position]大
	int pivot_position = Partition(array, left, right);
	QuickSort(array, left, pivot_position - 1);
	QuickSort(array, pivot_position + 1, right);
}

int main(int argc, char* argv[])
{
	//vector<int> array{ 1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56 };
	vector<int> array{100,  8, 4, 12, 13, 1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56 };
	cout << "原始数组：" << endl;
	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << ",";
	}
	cout << endl;
	QuickSort(array, 0, array.size() - 1);
	cout << "排序后的数组：" << endl;
	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << ",";
	}
	cout << endl;
	return 0;
}
