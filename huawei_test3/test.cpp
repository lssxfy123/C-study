// Copyright 2019.刘珅珅
// author：刘珅珅
// 模板实现快速排序
#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename Comparator>
int Partition(vector<T>& array, int left, int right, Comparator compare)
{
	T pivot = array[left];
	int pivot_position = left;
	for (int i = left + 1; i <= right; ++i)
	{
		if (compare(array[i], pivot))
		{
			++pivot_position;
			// ++pivot_position之后，如果i!=pivot_position，则array[pivot_position]>=pivot
			// 否则i肯定等于pivot_position
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

// 参考std::sort的实现方式
template<typename T, typename Comparator>
void QuickSort(vector<T>& array, int left, int right, Comparator compare)
{
	if (left >= right)
	{
		return;
	}

	int pivot_position = Partition(array, left, right, compare);
	QuickSort(array, left, pivot_position - 1, compare);
	QuickSort(array, pivot_position + 1, right, compare);
}

template<typename T>
void QuickSort(vector<T>& array, int left, int right)
{
	QuickSort(array, left, right, less<T>());
}

 class Test
{
public:
	Test()
	{
		number_ = 0;
	}

	Test(int number):number_(number)
	{}

	bool operator()(const Test& lhs, const Test& rhs) const
	{
		return lhs.number_ < rhs.number_;
	}

public:
	int number_;
};

int main(int argc, char* argv[])
{
	vector<int> array1{ 1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56 };
	vector<int> array{ 100,  8, 4, 12, 13, 1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56 };
	
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
	cout << endl;

	// 排序对象为类对象
	vector<Test> test_vec;
	test_vec.push_back(Test(1));
	test_vec.push_back(Test(8));
	test_vec.push_back(Test(4));
	test_vec.push_back(Test(12));
	test_vec.push_back(Test(2));
	test_vec.push_back(Test(29));
	cout << "原始数组：" << endl;
	for (int i = 0; i < test_vec.size(); ++i)
	{
		cout << test_vec[i].number_ << ",";
	}
	cout << endl;

	// 自定义的排序规则
	QuickSort(test_vec, 0, test_vec.size() - 1, Test());

	cout << "排序后的数组：" << endl;
	for (int i = 0; i < test_vec.size(); ++i)
	{
		cout << test_vec[i].number_ << ",";
	}
	return 0;
}
