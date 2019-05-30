// Copyright 2019.���|�|
// author�����|�|
// ģ��ʵ�ֿ�������
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
			// ++pivot_position֮�����i!=pivot_position����array[pivot_position]>=pivot
			// ����i�϶�����pivot_position
			// ����array[i]��array[pivot_position]��������Ϊ�˽�����С��pivot��Ԫ����������
			// ��ѭ��������ֻ�轻��array[left]��array[pivot_position]��pivot_position��ߵ�Ԫ��
			// �϶�С��pivot���ұߵĴ��ڵ���pivot
			if (i != pivot_position)
			{
				swap(array[i], array[pivot_position]);
			}
		}
	}

	if (left != pivot_position)
	{
		// ִ��һ�ν�������ŦԪpivotԭʼ��leftλ��
		// ��������for�ıȽϹ���array[pivot_position]�϶�С��pivot
		// ִ�н�����array[pivot_position]����pivot
		swap(array[left], array[pivot_position]);
	}

	return pivot_position;
}

// �ο�std::sort��ʵ�ַ�ʽ
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
	
	cout << "ԭʼ���飺" << endl;
	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << ",";
	}
	cout << endl;
	QuickSort(array, 0, array.size() - 1);
	cout << "���������飺" << endl;
	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << ",";
	}
	cout << endl;
	cout << endl;

	// �������Ϊ�����
	vector<Test> test_vec;
	test_vec.push_back(Test(1));
	test_vec.push_back(Test(8));
	test_vec.push_back(Test(4));
	test_vec.push_back(Test(12));
	test_vec.push_back(Test(2));
	test_vec.push_back(Test(29));
	cout << "ԭʼ���飺" << endl;
	for (int i = 0; i < test_vec.size(); ++i)
	{
		cout << test_vec[i].number_ << ",";
	}
	cout << endl;

	// �Զ�����������
	QuickSort(test_vec, 0, test_vec.size() - 1, Test());

	cout << "���������飺" << endl;
	for (int i = 0; i < test_vec.size(); ++i)
	{
		cout << test_vec[i].number_ << ",";
	}
	return 0;
}
