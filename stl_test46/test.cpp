// Copyright 2017.���|�|
// author�����|�|
// ������list
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

    // ��list1������Ԫ��Ų�Ƶ�list2��ĩ��
    // ��ʱ��list1��Ϊ������
    list2.splice(list2.end(), list1);
    PrintLists(list1, list2);

    // ��list2�ĵ�1��Ԫ��Ų��ĩ��
    list2.splice(list2.end(), list2, list2.begin());
    PrintLists(list1, list2);

    list2.sort();
    list1 = list2;

    // �Ƴ��������ڲ���ֵ��ͬ��Ԫ�أ�ֻ����һ��
    list2.unique();
    PrintLists(list1, list2);

    // �����������������ϲ�
    // ���Һϲ����list��Ϊ����
    // ��ʱlist2Ϊ������
    list1.merge(list2);
    PrintLists(list1, list2);
    return 0;
}
