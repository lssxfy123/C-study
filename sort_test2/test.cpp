// Copyright 2017.���|�|
// author�����|�|
// ��������

// �鲢����
// �ϲ�һ���������������Ĳ���
// array��left_pos��right_pos-1�������
// right_pos��right_end�������
// temp_arrayΪ��ʱ�洢�ϲ��������
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
        // array������С�ڵ���������
        if (array[left_pos] <= array[right_pos])
        {
            temp_array[temp_pos] = array[left_pos];
            ++temp_pos;
            ++left_pos;
        } else {  // ������С��������
            temp_array[temp_pos] = array[right_pos];
            ++temp_pos;
            ++right_pos;
        }
    }

    // array�������򲿷ֱ��������
    while (left_pos <= left_end)
    {
        temp_array[temp_pos++] = array[left_pos++];
    }

    // array�������򲿷ֱ��������
    while (right_pos <= right_end)
    {
        temp_array[temp_pos++] = array[right_pos++];
    }

    for (int i = 0; i < number_elements; ++i, --right_end)
    {
        array[right_end] = temp_array[right_end];
    }
}


// ������array��Ϊ�������֣��ֱ�����
// Ȼ����ϲ�
// �����˵ݹ�ķ�ʽ��ʵ��
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
    cout << "�鲢����:" << endl;
    MergeSort(array_test);
    return 0;
}
