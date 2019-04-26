// Copyright 2017.刘珅珅
// author：刘珅珅
// 基本排序
#include <iostream>
#include <vector>
using namespace std;

// 插入排序
template<typename Comparable>
void InsertionSort(vector<Comparable>& array)
{
    int j;
    for (int i = 1; i < array.size(); ++i)
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

    // 打印
    for (int k = 0; k < array.size(); ++k)
    {
        cout << array[k] << " ";
    }
    cout << endl;
}

// 希尔排序
template<typename Comparable>
void ShellSort(vector<Comparable>& array)
{
    // 增量序列
    vector<int> gap_array;
    gap_array.push_back(5);
    gap_array.push_back(3);
    gap_array.push_back(1);
    for (int k = 0; k < gap_array.size(); ++k)
    {
        // gap为增量
        int gap = gap_array[k];
        for (int i = gap; i < array.size(); ++i)
        {
            Comparable temp = array[i];
            int j = i;

            // array[i]与array[i - gap]比较
            for (; j >= gap && temp < array[j - gap]; j -= gap)
            {
                // 移动数组
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }

        cout << "gap = " << gap << endl;
        for (int i = 0; i < array.size(); ++i)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

// 堆排序
// 左儿子的索引值
// 与二叉堆不同的是其0位置有元素
// 二叉堆的0位置没有元素
inline int LefChild(int i)
{
    return 2 * i + 1;
}

// 下滤
template<typename Comparable>
void PercolateDown(vector<Comparable>& array, int i, int n)
{
    int child;
    Comparable temp = array[i];

    for (; LefChild(i) < n; i = child)
    {
        child = LefChild(i);

        // 最大堆，小值下滤
		// 查看左孩子和右孩子谁更大
        if (child != n - 1 && array[child] < array[child + 1])
        {
            ++child;
        }

        if (temp < array[child])
        {
            array[i] = array[child];
        } else
            break;
    }
    array[i] = temp;
}

template<typename Comparable>
void HeapSort(vector<Comparable>& array)
{
    // 建立堆序
    for (int i = array.size() / 2; i >= 0; --i)
    {
        PercolateDown(array, i, array.size());
    }

    // 排序
    for (int j = array.size() - 1; j > 0; --j)
    {
        // array[0]肯定是数组的最大值
        // 排序开始，将array[0]与array[array.size() - 1]交换
        // 这样最大值就换到了数组末，然后执行下滤操作
        // 注意是前array.size() - 1项的下滤，最后一项不参与
        // 这样把前array.size() - 1项的最大值移动到了array[0]位置
        swap(array[0], array[j]);
        PercolateDown(array, 0, j);
    }

    // 打印
    for (int k = 0; k < array.size(); ++k)
    {
        cout << array[k] << " ";
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
    cout << "插入排序:" << endl;
    InsertionSort(array_test);

    vector<int> array_test1;
    array_test1.push_back(81);
    array_test1.push_back(94);
    array_test1.push_back(11);
    array_test1.push_back(96);
    array_test1.push_back(12);
    array_test1.push_back(35);
    array_test1.push_back(17);
    array_test1.push_back(95);
    array_test1.push_back(28);
    array_test1.push_back(58);
    array_test1.push_back(41);
    array_test1.push_back(75);
    array_test1.push_back(15);
    cout << "希尔排序:" << endl;
    ShellSort(array_test1);

    vector<int> array_test2;
    array_test2.push_back(34);
    array_test2.push_back(8);
    array_test2.push_back(64);
    array_test2.push_back(51);
    array_test2.push_back(32);
    array_test2.push_back(21);
    cout << "堆排序:" << endl;
    HeapSort(array_test2);
    return 0;
}
