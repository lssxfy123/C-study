// Copyright 2017.���|�|
// author�����|�|
// �������ݲ��ҵ�k�����ֵ

#include <iostream>
#include <ctime>
#include <Windows.h>
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
    int max = 20000000;
    int length = 10000000;
    SYSTEMTIME st = {0};

    for (int i = 0; i < length; ++i)
    {
        array_test.push_back(rand() % (max - min + 1) + min);
    }

    GetLocalTime(&st);
    cout << "��ʼ���� " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    int k_min = QuickSelect(array_test, 500000);
    GetLocalTime(&st);
    cout << "���ҽ��Ϊ "  << k_min <<endl;
    cout << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    return 0;
}
