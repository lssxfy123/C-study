// Copyright 2015.
// author�����|�|
// �Զ���List����

#include <iostream>
#include <list>
using namespace std;

#include "List.hpp"

int main(int argc, char* argv[])
{
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    int k = list1.back();

    cout << k << endl;

    List<int>::const_iterator iter;

    List<int> list2(list1);

    for (iter = list2.begin(); iter != list2.end(); ++iter)
    {
        cout << *iter << ",";
    }

    cout << endl;
    return 0;
}