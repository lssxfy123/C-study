// Copyright 2017.刘珅珅
// author：刘珅珅
// 大量数据查找第k个最大值

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
using namespace std;

// 插入排序
// 数组长度比较小时使用插入排序
// 只排数组的一部分
template<typename Comparable>
void InsertionSort(vector<Comparable>& array, int left, int right)
{
    int j;
    for (int i = left + 1; i <= right; ++i)
    {
        Comparable temp = array[i];
        // 第i个元素与之前的0-i - 1进行比较
        for (j = i; j > 0 && temp < array[j - 1]; --j)
        {
            // 移动数组
            // 如果temp<array[j - 1]，将array[j - 1]向后移动
            // 以便插入temp
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }
}

// 三数中值分割法
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
    // array[center]为枢纽元
    // 交换array[center]与array[right - 1]，是因为
    // array[right] > array[center]，将枢纽元放置在right - 1位置
    // 这样后续的比较可以少比较一次
    swap(array[center], array[right - 1]);
    return array[right - 1];
}


// 快速选择，找到第k个最小值
template<typename Comparable>
void QuickSelect(vector<Comparable>& array, int left, int right, int k)
{
    if (left + 10 <= right)
    {
        // 枢纽元
        Comparable pivot = Median3(array, left, right);
        int i = left;
        int j = right - 1;  // right位置的元素肯定比pivot大
        for (; ;)
        {
            // 左边小于枢纽元
            while (array[++i] < pivot)
            {
            }

            // 右边大于枢纽元
            while (pivot < array[--j])
            {
            }

            if (i < j)
            {
                swap(array[i] , array[j]);
            } else
                break;
        }

        // 退出上面的for循环
        // 说明array[i] >= array[right - 1]
        // 交换它们进行排序
        // array[i]存储的就是pivot
        swap(array[i], array[right - 1]);

        if (k <= i)
        {
            // 只排left到i - 1的元素
            QuickSelect(array, left, i - 1, k);
        } else if (k > i)
        {
            // 只排i + 1到right的元素
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

    //生成随机数
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
    cout << "开始查找 " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    int k_min = QuickSelect(array_test, 500000);
    GetLocalTime(&st);
    cout << "查找结果为 "  << k_min <<endl;
    cout << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
    return 0;
}
