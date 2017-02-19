// Copyright 2016.刘珅珅
// author：刘珅珅
// 最小顶二叉堆-优先队列
#include <iostream>
using namespace std;

#include "binaryheap.hpp"

int main(int argc, char* argv[])
{
    vector<int> array1;
    array1.push_back(3);
    array1.push_back(4);

    // 执行resize操作,会插入相应的元素
    // 使array1满足设置的值,本例中会插入
    // 8个0,总共10个值
    array1.resize(10);
    array1.push_back(5);

    int current_size = 11;
    cout << array1[--current_size] << endl;

    BinaryHeap<int> binary_heap;
    binary_heap.Insert(13);
    binary_heap.Insert(21);
    binary_heap.Insert(16);
    binary_heap.Insert(24);
    binary_heap.Insert(31);
    binary_heap.Insert(19);
    binary_heap.Insert(68);
    binary_heap.Insert(65);
    binary_heap.Insert(26);
    binary_heap.Insert(32);
    binary_heap.Print();
    binary_heap.Insert(14);
    binary_heap.Print();

    while (!binary_heap.IsEmpty())
    {
        int temp = 0;
        binary_heap.DeleteMin(temp);
        cout << temp << " ";
    }
    cout << endl;

    vector<int> array_test;
    array_test.push_back(69);
    array_test.push_back(31);
    array_test.push_back(53);
    array_test.push_back(60);
    array_test.push_back(38);
    array_test.push_back(71);
    array_test.push_back(96);
    array_test.push_back(20);
    array_test.push_back(34);
    array_test.push_back(87);
    array_test.push_back(28);
    array_test.push_back(95);
    array_test.push_back(53);
    array_test.push_back(80);
    array_test.push_back(60);
    BinaryHeap<int> binary_heap_test(array_test);
    while (!binary_heap_test.IsEmpty())
    {
        int temp =0;
        binary_heap_test.DeleteMin(temp);
        cout << temp << " ";
    }
    cout << endl;
    return 0;
}