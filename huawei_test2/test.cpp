// Copyright 2019.���|�|
// author�����|�|
// ����Ŀ�������
#include <iostream>
#include <vector>
using namespace std;

// 3��λ���ҷָ�λ��
// ��������
// ������򣬾ͽ��ȽϷ��Ϸ�ת
int Median3Index(vector<int>& nums, int left, int right)
{
	int center = (left + right) / 2;
	if (nums[center] > nums[left])
	{
		swap(nums[center], nums[left]);
	}

	if (nums[right] > nums[left])
	{
		swap(nums[right], nums[left]);
	}

	if (nums[center] > nums[right])
	{
		swap(nums[center], nums[right]);
	}

	return left;
}


// ����
int Partition(vector<int>& array, int left, int right)
{
	int pivot_position = Median3Index(array, left, right);
	int pivot = array[pivot_position];
	int tmp = pivot_position;
	
	for (int i = left; i <= right; ++i)
	{
		// ���array[i]<pivot��������++pivot_position
		// pivot_position��ʼ�������(Ĭ��û��Ԫ��С��pivot)����array[i]<pivotʱ
		// ����pivot_position��Ҫ����:pivot_position���Ԫ�ر�pivotС���ұ߱�pivot��
		// ����++pivot_position
		if (array[i] < pivot && i != tmp)
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

	if (tmp != pivot_position)
	{
		// ִ��һ�ν�������ŦԪpivotԭʼ��tmpλ��
		// ��������for�ıȽϹ���array[pivot_position]�϶�С��pivot
		// ִ�н�����array[pivot_position]����pivot
		swap(array[tmp], array[pivot_position]);
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

	vector<int> array1{ 595240,373125,463748,417209,209393,747977,864346,419023,925673,307640,597868,833339,130763,814627,766415,79576,459038,990103,944521,708820,473246,499960,742286,758503,270229,991199,770718,529265,498975,721068,727348,29619,712557,724373,823743,318203,290432,476213,412181,869308,496482,793858,676162,165869,160511,260864,502521,611678,786798,356560,916620,922168,89350,857183,964051,979979,916565,186532,905289,653307,351329,195491,866281,183964,650765,675046,661642,578936,78684,50105,688326,648786,645823,652329,961553,381367,506439,77735,707959,373271,316194,185079,686945,342608,980794,78777,687520,27772,711098,661265,167824,688245,286419,400823,198119,35400,916784,81169,874377,377128,922531,866135,319912,867697,10904 };
	QuickSort(array1, 0, array1.size() - 1);
	for (int i = 0; i < array1.size(); ++i)
	{
		cout << array1[i] << ",";
	}
	cout << endl;
	return 0;
}
