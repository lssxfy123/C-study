// Copyright 2017.刘珅珅
// author：刘珅珅
// reverse_iterator
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "正向迭代器指向元素的地址" << endl;
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << hex << &(*(iter)) <<endl;
    }

    cout << endl;

    cout << "反向迭代器指向元素的地址" << endl;
    for (auto r_iter = v.rbegin(); r_iter != v.rend(); ++r_iter)
    {
        cout << hex << &(*(r_iter)) << endl;
    }
    cout << endl;

    cout << "通过反向迭代器的base()获取的迭代器指向元素的地址" << endl;
    for (auto iter = v.rend().base(); iter != v.rbegin().base(); ++iter)
    {
        cout << hex << &(*(iter)) << endl;
    }


    return 0;
}
