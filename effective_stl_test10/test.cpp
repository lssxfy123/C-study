// Copyright 2017.���|�|
// author�����|�|
// reverse_iterator
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "���������ָ��Ԫ�صĵ�ַ" << endl;
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << hex << &(*(iter)) <<endl;
    }

    cout << endl;

    cout << "���������ָ��Ԫ�صĵ�ַ" << endl;
    for (auto r_iter = v.rbegin(); r_iter != v.rend(); ++r_iter)
    {
        cout << hex << &(*(r_iter)) << endl;
    }
    cout << endl;

    cout << "ͨ�������������base()��ȡ�ĵ�����ָ��Ԫ�صĵ�ַ" << endl;
    for (auto iter = v.rend().base(); iter != v.rbegin().base(); ++iter)
    {
        cout << hex << &(*(iter)) << endl;
    }


    return 0;
}
