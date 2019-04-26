// Copyright 2017.���|�|
// author�����|�|
// ��������

// ��������
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// ��������
// ���鳤�ȱȽ�Сʱʹ�ò�������
// ֻ�������һ����
template<typename Comparable>
void InsertionSort(vector<Comparable>& array, int left, int right)
{
    int j;
    for (int i = left + 1; i <= right; ++i)
    {
        Comparable temp = array[i];
        // ��i��Ԫ����֮ǰ��0-i - 1���бȽ�
        for (j = i; j > 0 && temp < array[j - 1]; --j)
        {
            // �ƶ�����
            // ���temp<array[j - 1]����array[j - 1]����ƶ�
            // �Ա����temp
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }
}

// ������ֵ�ָ
template<typename Comparable>
const Comparable& Median3(vector<Comparable>& array, int left, int right)
{
    int center = (left + right) / 2;
    if (array[center] < array[left])
    {
        swap(array[left], array[center]);
    }

    if (array[right] < array[left])
    {
        swap(array[left] , array[right]);
    }

    if (array[right] < array[center])
    {
        swap(array[right], array[center]);
    }

    // array[left] < array[center] < array[right]
    // array[center]Ϊ��ŦԪ
    // ����array[center]��array[right - 1]������Ϊ
    // array[right] > array[center]������ŦԪ������right - 1λ��
    // ���������ıȽϿ����ٱȽ�һ��
    swap(array[center], array[right - 1]);
    return array[right - 1];
}

template<typename Comparable>
void QuickSort(vector<Comparable>& array, int left, int right)
{
    if (left + 10 <= right)
    {
        // ��ŦԪ
        Comparable pivot = Median3(array, left, right);
        int i = left;
        int j = right - 1;  // rightλ�õ�Ԫ�ؿ϶���pivot��
        for (; ;)
        {
            // ���С����ŦԪ
            while (array[++i] < pivot)
            {
            }

            // �ұߴ�����ŦԪ
            while (pivot < array[--j])
            {
            }

            if (i < j)
            {
                swap(array[i] , array[j]);
            } else
               break;
        }

        // �˳������forѭ��
        // ˵��array[i] >= array[right - 1]����Ϊ��Median3��pivot=array[right-1]
        // �������ǽ�������
        // array[i]�洢�ľ���pivot
        swap(array[i], array[right - 1]);

        // left��i - 1�϶�С��pivot
        QuickSort(array, left, i - 1);

        // i + 1��right�϶�����pivot
        QuickSort(array, i + 1, right);
    } else {
        // ���left��right֮��Ĳ��С��10
        // ��ִ�в�������
        cout << "ִ�в�������" << " left = " 
            << left << " right = " << right <<  endl;
        InsertionSort(array, left, right);
    }
}

template<typename Comparable>
void QuickSort(vector<Comparable>& array)
{
    QuickSort(array, 0, array.size() - 1);

    for (int i = 0; i < array.size(); ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


// ����ѡ���ҵ���k����Сֵ
template<typename Comparable>
void QuickSelect(vector<Comparable>& array, int left, int right, int k)
{
    if (left + 10 <= right)
    {
        // ��ŦԪ
        Comparable pivot = Median3(array, left, right);
        int i = left;
        int j = right - 1;  // rightλ�õ�Ԫ�ؿ϶���pivot��
        for (; ;)
        {
            // ���С����ŦԪ
            while (array[++i] < pivot)
            {
            }

            // �ұߴ�����ŦԪ
            while (pivot < array[--j])
            {
            }

            if (i < j)
            {
                swap(array[i] , array[j]);
            } else
                break;
        }

        // �˳������forѭ��
        // ˵��array[i] >= array[right - 1]
        // �������ǽ�������
        // array[i]�洢�ľ���pivot
        swap(array[i], array[right - 1]);

        if (k <= i)
        {
            // ֻ��left��i - 1��Ԫ��
            QuickSelect(array, left, i - 1, k);
        } else if (k > i)
        {
            // ֻ��i + 1��right��Ԫ��
            QuickSelect(array, i + 1, right, k);
        }
    } else {
        InsertionSort(array, left, right);
    }
}

template<typename Comparable>
Comparable QuickSelect(vector<Comparable> array, int k)
{
    QuickSelect(array, 0, array.size() - 1, k);
    return array[k - 1];
}

int main(int argc, char* argv[])
{
    vector<int> array_test;

    //���������
    srand( (unsigned)time(NULL));
    int min = 0;
    int max = 100;
    int length = 50;
    for (int i = 0; i < length; ++i)
    {
        array_test.push_back(rand() % (max - min + 1) + min);
    }

    cout << "ԭʼ����" << endl;
    for (int i = 0; i < array_test.size(); ++i)
    {
        cout << array_test[i] << " ";
    }
    cout << endl;
    cout << "��������:" << endl;
    QuickSort(array_test);

    vector<int> array_select;
    for (int i = 0; i < length; ++i)
    {
        array_select.push_back(rand() % (max - min + 1) + min);
    }

    cout << "����ѡ��" << endl;
    cout << "ԭʼ����" << endl;
    for (int i = 0; i < array_select.size(); ++i)
    {
        cout << array_select[i] << " ";
    }
    cout << endl;
    int k = 5;
    int k_min = QuickSelect(array_select, k);
    cout << "�� " << k << " ����СֵΪ" << k_min << endl;
    return 0;
}
