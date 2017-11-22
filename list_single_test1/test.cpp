// Copyright 2015.
// author：刘珅珅
// 自定义单链表

#include <iostream>
#include <list>
using namespace std;

#include "SingleList.hpp"

int main(int argc, char* argv[])
{
    SingleList<int> single_list;
    single_list.add(1);
    single_list.add(2);
    single_list.add(3);
    single_list.add(4);

    single_list.print();

    SingleList<int> single_list1(single_list);
    single_list1.print();

    list<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    list<int> list2(list1);

    for (list<int>::iterator itr = list2.begin(); itr != list2.end(); ++itr)
    {
        cout << (*itr) << ",";
    }
    cout << endl;
    //single_list.print();

    return 0;
}
