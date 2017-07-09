// Copyright 2017.���|�|
// author�����|�|
// ������������������ʽ������������
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> coll2;
    // ��������ĩ��
    // ���ڲ�����push_backִ�в���
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
    for (const auto& elem : coll2)
    {
        cout << elem << ' ';
    }
    cout << endl;

    //vector<int> coll3;  // error��vector����ִ��push_front����
    deque<int> coll3;
    // ��������ǰ��
    // ���ڲ�ִ��push_front����
    copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));
    for (const auto& elem : coll3)
    {
        cout << elem << ' ';
    }
    cout << endl;

    set<int> coll4;
    // һ���Բ��룬�ڲ�����insert()����
    // �������ڹ���ʽ��������������
    copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
    for (const auto& elem : coll4)
    {
        cout << elem << ' ';
    }
    cout << endl;
    return 0;
}
