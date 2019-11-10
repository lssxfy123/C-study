// Copyright 2019.刘珅珅
// author：刘珅珅
// 另一种理解优先队列的方式
#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int heap[1000];
int heap_size = 0;

void push(int x)
{
    int index = ++heap_size;  // 首先插入到最后一个位置

    // 上滤
    while (index > 1)
    {
        int parent_index = index / 2;
        if (heap[parent_index] <= x)  // 最小堆
        {
            // 不需要调整
            break;
        }

        heap[index] = heap[parent_index];  // 大小颠倒

        // 还要继续进行上滤操作，原因是执行了上一步的大小颠倒后
        // 还需要继续为x查找位置，根据最小堆的性质父结点的值要小于
        // 子结点以及其所有后裔的值
        index = parent_index;
    }

    heap[index] = x;
}

int pop()
{
    int result = heap[1];  // 获取最小值或最大值，编号从1开始
    int x = heap[heap_size--];  // 堆中的最后一个结点
    int index = 1;

    // 下滤
    while (index * 2 <= heap_size)  // 保证有子结点，否则不需要下滤
    {
        int left_index = 2 * index;
        int right_index = 2 * index + 1;
        int min_index = left_index;

        // 查找左右孩子中的较小值
        if (right_index <= heap_size && heap[right_index] < heap[min_index])
        {
            min_index = right_index;
        }

        if (heap[min_index] >= x)
        {
            // 不需要调整
            break;
        }

        // 上下颠倒交换
        heap[index] = heap[min_index];
        index = min_index;
    }
    heap[index] = x;
    return result;
}

void BuildHeap(vector<int>& array)
{
    heap_size = 0;
    for (int i = 0; i < array.size(); ++i)
    {
        push(array[i]);
    }
}

int main(int argc, char* argv[])
{
    vector<int> array{10, 8, 1, 3, 4, 5, 7, 9};
    BuildHeap(array);
    cout << pop() << endl;
    return 0;
}
