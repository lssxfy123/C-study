// Copyright 2017.���|�|
// author�����|�|
// ������forward_list
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

    // ͷ������Ԫ��
    list2.insert_after(list2.before_begin(), 99);
    list2.push_front(10);
    list2.insert_after(list2.before_begin(), {10, 11, 12, 13});
    PrintLists("6 new elems: ", list1, list2);

    list1.insert_after(list1.before_begin(), list2.begin(), list2.end());
    PrintLists("list2 into list1: ", list1, list2);

    // ɾ����2��Ԫ��
    list2.erase_after(list2.begin());
    // ɾ����1��99�������Ԫ��
    list2.erase_after(find(list2.begin(), list2.end(), 99), list2.end());
    PrintLists("delete 2nd and after 99:", list1, list2);

    list1.sort(less<int>());
    list2 = list1;
    list2.unique();  // ɾ�����ڵ���ͬԪ�أ�ֻ����1��
    PrintLists("sorted and unique:  ", list1, list2);

    // �ϲ����ұ�������
    list1.merge(list2);
    PrintLists("merged:  ", list1, list2);
    return 0;
}
