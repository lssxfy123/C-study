// Copyright 2019.���|�|
// author�����|�|
// ��k��Ԫ��
// ��ע��ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
// ʹ�ÿ��ٲ���
#include <algorithm>
#include <functional>
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

int partition(vector<int>& array, int left, int right)
{
    int pivot = array[left];
    int pivot_position = left;

    for (int i = left + 1; i <= right; ++i)
    {
        if (array[i] > pivot)
        {
            ++pivot_position;
            if (i != pivot_position)
            {
                swap(array[i], array[pivot_position]);
            }
        }
    }

    if (pivot_position != left)
    {
        swap(array[left], array[pivot_position]);
    }

    return pivot_position;
}

void QuickSelect1(vector<int>& nums, int left, int right, int k)
{
    if (left >= right)
    {
        return;
    }

    if (left + 10 <= right)
    {
        int pivot_position = partition(nums, left, right);
        //if (k == pivot_position - 1)
        //{
        //    return;
        //}

        //if (k < pivot_position - 1)
        {
            QuickSelect1(nums, 0, pivot_position - 1, k);
        }
        //else
        {
            QuickSelect1(nums, pivot_position + 1, right, k);
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

int kthLargestElement1(int n, vector<int> &nums) {
    // write your code here
    if (nums.size() == 0 || n <= 0 || n > nums.size())
    {
        return -1;
    }

    QuickSelect1(nums, 0, nums.size() - 1, n);
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

    vector<int> vec3{ 595240,373125,463748,417209,209393,747977,864346,419023,925673,307640,597868,833339,130763,814627,766415,79576,459038,990103,944521,708820,473246,499960,742286,758503,270229,991199,770718,529265,498975,721068,727348,29619,712557,724373,823743,318203,290432,476213,412181,869308,496482,793858,676162,165869,160511,260864,502521,611678,786798,356560,916620,922168,89350,857183,964051,979979,916565,186532,905289,653307,351329,195491,866281,183964,650765,675046,661642,578936,78684,50105,688326,648786,645823,652329,961553,381367,506439,77735,707959,373271,316194,185079,686945,342608,980794,78777,687520,27772,711098,661265,167824,688245,286419,400823,198119,35400,916784,81169,874377,377128,922531,866135,319912,867697,10904 };
    k = 100;
    sort(vec3.begin(), vec3.end(), greater<int>());
    cout << kthLargestElement1(k, vec3) << endl;
	return 0;
}
