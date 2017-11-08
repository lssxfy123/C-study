// Copyright 2017.刘珅珅
// author：刘珅珅
// 清除vector和string多余的容量
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vec;
    vec.reserve(10);
    vec.push_back(1);
    vec.push_back(2);
    cout << "capacity size = " << vec.capacity() << endl;

    // 通过swap来清除多余的容量
    // 创建一个临时的vector并拷贝vec
    // 拷贝时只会为所拷贝的元素分配内存
    // 所以这个临时的vector没有多余的空间
    vector<int>(vec).swap(vec);
    cout << "capacity size = " << vec.capacity() << endl;

    // 清空vector
    vector<int>().swap(vec);
    return 0;
}
