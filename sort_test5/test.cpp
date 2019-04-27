// Copyright 2017.���|�|
// author�����|�|
// �������ݲ���ǰk�����ֵ
#include <algorithm>
#include <functional>
#include <iostream>
#include <ctime>
#include <random>
#include <Windows.h>
#include <vector>
using namespace std;

const int kBigArraySize = 10000000;
const int kResultArraySize = 10000;

template<typename Comparable>
void FindKMaxNumbers(vector<Comparable>& array, vector<Comparable>& result_array)
{
    // ǰkResultArraySize��Ԫ�ط��ڽ������
    for (int i = 0; i < result_array.size(); ++i)
    {
        result_array[i] = array[i];
    }

    // k��Ԫ������
    sort(result_array.begin(), result_array.end(), greater<Comparable>());

    // ��СԪ������
    int min_element_index = kResultArraySize - 1;

    // ���ܲ��������������С����
    int zone_begin_index = min_element_index;

    // ��������Ԫ��
    for (int i = kResultArraySize; i < kBigArraySize; ++i)
    {
        // �������Ԫ�ر�result_array����СԪ�ش����滻
        if (array[i] > result_array[min_element_index])
        {
            result_array[min_element_index] = array[i];

            // zone_begin_index��result_array���������Сֵ�������ʼλ��
            // ��ʼֵΪkResultArraySize - 1�������һ��ֵ
            // ���result_array�е�ֵ��������ֵ�滻������Ҫ����Ѱ����Сֵ
            // ���min_element_index����zone_begin_index����--zone_begin_index����
            // ����ʼλ����ǰ�ƶ�1λ��ֻ�ƶ�1λ����Ϊ����ǰ��Ԫ�ؿ϶���
            // result_array[--zone_begin_index]��
            // ����min_element_indexΪ0�����
            if (min_element_index == zone_begin_index)
            {
                --zone_begin_index;
            }

            if (zone_begin_index < (kResultArraySize - 600))
            {
                // ��������600��Ԫ������ʱ����������
                // 600�Ǹ�����ֵ
                sort(result_array.begin(), result_array.end(), greater<Comparable>());
                zone_begin_index = min_element_index = kResultArraySize - 1;
                continue;
            }

            int index = zone_begin_index;
            // δ�������������£�������Сֵ
            // result_array��0-zone_begin_index��Ԫ���������
            // zone_begin_index+1-kResultArraySize-1��δ�����
            for (int j = index + 1; j < kResultArraySize; ++j)
            {
                if (result_array[index] > result_array[j])
                {
                    index = j;
                }
            }
            min_element_index = index;
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> array_test;

    //���������
    default_random_engine e(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<int> u(0, 10000000);

    int min = 0;
    int max = kBigArraySize;
    int length = kBigArraySize;
    SYSTEMTIME st = {0};

    for (int i = 0; i < length; ++i)
    {
        array_test.push_back(u(e));
    }

    vector<int> result_array(kResultArraySize);
    GetLocalTime(&st);
    cout << "��ʼ���� " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    FindKMaxNumbers(array_test, result_array);
    GetLocalTime(&st);
    cout << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    return 0;
}
