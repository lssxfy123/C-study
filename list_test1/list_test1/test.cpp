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
    return 0;
}
