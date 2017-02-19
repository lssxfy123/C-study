// Copyright 2017.刘珅珅
// author：刘珅珅
// 基本排序

// 归并排序
// 合并一个数组的两个有序的部分
// array的left_pos到right_pos-1是有序的
// right_pos到right_end是有序的
// temp_array为临时存储合并后的数组
#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void Merge(vector<Comparable>& array, vector<Comparable>& temp_array,
           int left_pos, int right_pos, int right_end)
{
    int left_end = right_pos - 1;
    int number_elements = right_end - left_pos + 1;
    int temp_pos = left_pos;

    while (left_pos <= left_end && right_pos <= right_end)
    {
        // array左有序小于等于右有序
        if (array[left_pos] <= array[right_pos])
        {
            temp_array[temp_pos] = array[left_pos];
            ++temp_pos;
            ++left_pos;
        } else {  // 右有序小于左有序
            temp_array[temp_pos] = array[right_pos];
            ++temp_pos;
            ++right_pos;
        }
    }

    // array的左有序部分比右有序多
    while (left_pos <= left_end)
    {
        temp_array[temp_pos++] = array[left_pos++];
    }

    // array的右有序部分比左有序多
    while (right_pos <= right_end)
    {
        temp_array[temp_pos++] = array[right_pos++];
    }

    for (int i = 0; i < number_elements; ++i, --right_end)
    {
        array[right_end] = temp_array[right_end];
    }
}


// 将数组array分为两个部分，分别排序
// 然后将其合并
// 采用了递归的方式来实现
template<typename Comparable>
void MergeSort(vector<Comparable>& array, vector<Comparable>& temp_array, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        MergeSort(array, temp_array, left, center);
        MergeSort(array, temp_array, center + 1, right);
        Merge(array, temp_array, left, center + 1, right);
    }
}

template<typename Comparable>
void MergeSort(vector<Comparable>& array)
{
    vector<Comparable> temp_array(array.size());
    MergeSort(array, temp_array, 0, array.size() - 1);

    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    vector<int> array_test;
    array_test.push_back(34);
    array_test.push_back(8);
    array_test.push_back(64);
    array_test.push_back(51);
    array_test.push_back(32);
    array_test.push_back(21);
    cout << "归并排序:" << endl;
    MergeSort(array_test);
    return 0;
}
