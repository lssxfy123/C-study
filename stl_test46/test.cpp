// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：list
#include <algorithm>
#include <functional>
#include <list>
#include <iostream>
#include <iterator>
#include "../include/print.hpp"
using namespace std;

void PrintLists(const list<int>& list1, const list<int>& list2)
{
    cout << "list1:   ";
    copy(list1.cbegin(), list1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << "list2:   ";
    copy(list2.cbegin(), list2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}

int main(int argc, char* argv[])
{
    list<int> list1, list2;
    for (int i = 0; i < 6; ++i)
    {
        list1.push_back(i);
        list2.push_front(i);
    }
    PrintLists(list1, list2);

    // 将list1的所有元素挪移到list2的末端
    // 此时的list1将为空链表
    list2.splice(list2.end(), list1);
    PrintLists(list1, list2);

    // 将list2的第1个元素挪到末端
    list2.splice(list2.end(), list2, list2.begin());
    PrintLists(list1, list2);

    list2.sort();
    list1 = list2;

    // 移除若干相邻并且值相同的元素，只保留一个
    list2.unique();
    PrintLists(list1, list2);

    // 将两个已排序的链表合并
    // 并且合并后的list仍为排序
    // 此时list2为空链表
    list1.merge(list2);
    PrintLists(list1, list2);
    return 0;
}
