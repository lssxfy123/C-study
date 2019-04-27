// Copyright 2017.刘珅珅
// author：刘珅珅
// 大量数据查找前k个最大值
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
    // 前kResultArraySize个元素放在结果数组
    for (int i = 0; i < result_array.size(); ++i)
    {
        result_array[i] = array[i];
    }

    // k个元素排序
    sort(result_array.begin(), result_array.end(), greater<Comparable>());

    // 最小元素索引
    int min_element_index = kResultArraySize - 1;

    // 可能产生交换区域的最小索引
    int zone_begin_index = min_element_index;

    // 遍历后续元素
    for (int i = kResultArraySize; i < kBigArraySize; ++i)
    {
        // 这个后续元素比result_array中最小元素大，则替换
        if (array[i] > result_array[min_element_index])
        {
            result_array[min_element_index] = array[i];

            // zone_begin_index是result_array数组存在最小值区域的起始位置
            // 初始值为kResultArraySize - 1，即最后一个值
            // 如果result_array中的值被后续的值替换，则需要重新寻找最小值
            // 如果min_element_index等于zone_begin_index，则--zone_begin_index，即
            // 将起始位置向前移动1位，只移动1位是因为再往前的元素肯定比
            // result_array[--zone_begin_index]大
            // 考虑min_element_index为0的情况
            if (min_element_index == zone_begin_index)
            {
                --zone_begin_index;
            }

            if (zone_begin_index < (kResultArraySize - 600))
            {
                // 重新排序，600个元素无序时就重新排序
                // 600是个经验值
                sort(result_array.begin(), result_array.end(), greater<Comparable>());
                zone_begin_index = min_element_index = kResultArraySize - 1;
                continue;
            }

            int index = zone_begin_index;
            // 未重新排序的情况下，查找最小值
            // result_array中0-zone_begin_index的元素是排序的
            // zone_begin_index+1-kResultArraySize-1是未排序的
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

    //生成随机数
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
    cout << "开始查找 " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    FindKMaxNumbers(array_test, result_array);
    GetLocalTime(&st);
    cout << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    return 0;
}
