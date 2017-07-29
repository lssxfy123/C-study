// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：forward_list
#include <algorithm>
#include <functional>
#include <forward_list>
#include <iostream>
#include <iterator>
#include "../include/print.hpp"
using namespace std;

void PrintLists(const string& str, const forward_list<int>& list1, const forward_list<int>& list2)
{
    cout << str << endl;
    cout << "list1:   ";
    copy(list1.cbegin(), list1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << "list2:   ";
    copy(list2.cbegin(), list2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
}

int main(int argc, char* argv[])
{
    forward_list<int> list1 = {1, 2, 3, 4};
    forward_list<int> list2 = {77, 88, 99};
    PrintLists("initial:  ", list1, list2);

    // 头部插入元素
    list2.insert_after(list2.before_begin(), 99);
    list2.push_front(10);
    list2.insert_after(list2.before_begin(), {10, 11, 12, 13});
    PrintLists("6 new elems: ", list1, list2);

    list1.insert_after(list1.before_begin(), list2.begin(), list2.end());
    PrintLists("list2 into list1: ", list1, list2);

    // 删除第2个元素
    list2.erase_after(list2.begin());
    // 删除第1个99后的所有元素
    list2.erase_after(find(list2.begin(), list2.end(), 99), list2.end());
    PrintLists("delete 2nd and after 99:", list1, list2);

    list1.sort(less<int>());
    list2 = list1;
    list2.unique();  // 删除相邻的相同元素，只保留1个
    PrintLists("sorted and unique:  ", list1, list2);

    // 合并并且保持排序
    list1.merge(list2);
    PrintLists("merged:  ", list1, list2);
    return 0;
}
