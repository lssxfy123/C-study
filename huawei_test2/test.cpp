// Copyright 2019.���|�|
// author�����|�|
// ����Ŀ�������
#include <iostream>
#include <vector>
using namespace std;

// ����
int Partition(vector<int>& array, int left, int right)
{
	int pivot = array[left];
	int pivot_position = left;
	for (int i = left + 1; i <= right; ++i)
	{
		// ���array[i]<pivot��������++pivot_position
		// pivot_position��ʼ�������(Ĭ��û��Ԫ��С��pivot)����array[i]<pivotʱ
		// ����pivot_position��Ҫ����:pivot_position���Ԫ�ر�pivotС���ұ߱�pivot��
		// ����++pivot_position
		if (array[i] < pivot)
		{
			++pivot_position;
            // i�϶����ڻ����pivot_position����ÿ��ѭ������+1
			// ++pivot_position֮�����i==pivot_position������ִ�н���
            // ���i!=pivot_position����array[pivot_position]>=pivot
			// ����ִ��++pivot_position֮ǰ���������ұߵ�Ԫ�ش��ڵ���pivot��Ҫ��
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

void QuickSort(vector<int>& array, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	// �ҳ�һ���ָ�λ�ã�left-pivot_position-1�е�
	// Ԫ�ؿ϶���array[pivot_position]С��pivot_position+1-right
	// �϶���array[pivot_position]��
	int pivot_position = Partition(array, left, right);
	QuickSort(array, left, pivot_position - 1);
	QuickSort(array, pivot_position + 1, right);
}

int main(int argc, char* argv[])
{
	//vector<int> array{ 1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56 };
	vector<int> array{100,  8, 4, 12, 13, 1, 6, 7, 8, 2, 9, 10, 12, 23, 5, 89, 24, 25, 26, 27, 34, 56 };
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
	return 0;
}
