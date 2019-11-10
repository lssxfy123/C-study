// Copyright 2019.���|�|
// author�����|�|
// ��һ��������ȶ��еķ�ʽ
#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int heap[1000];
int heap_size = 0;

void push(int x)
{
    int index = ++heap_size;  // ���Ȳ��뵽���һ��λ��

    // ����
    while (index > 1)
    {
        int parent_index = index / 2;
        if (heap[parent_index] <= x)  // ��С��
        {
            // ����Ҫ����
            break;
        }

        heap[index] = heap[parent_index];  // ��С�ߵ�

        // ��Ҫ�����������˲�����ԭ����ִ������һ���Ĵ�С�ߵ���
        // ����Ҫ����Ϊx����λ�ã�������С�ѵ����ʸ�����ֵҪС��
        // �ӽ���Լ������к����ֵ
        index = parent_index;
    }

    heap[index] = x;
}

int pop()
{
    int result = heap[1];  // ��ȡ��Сֵ�����ֵ����Ŵ�1��ʼ
    int x = heap[heap_size--];  // ���е����һ�����
    int index = 1;

    // ����
    while (index * 2 <= heap_size)  // ��֤���ӽ�㣬������Ҫ����
    {
        int left_index = 2 * index;
        int right_index = 2 * index + 1;
        int min_index = left_index;

        // �������Һ����еĽ�Сֵ
        if (right_index <= heap_size && heap[right_index] < heap[min_index])
        {
            min_index = right_index;
        }

        if (heap[min_index] >= x)
        {
            // ����Ҫ����
            break;
        }

        // ���µߵ�����
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
