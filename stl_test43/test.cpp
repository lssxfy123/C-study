// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：array
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    array<int, 3> arr1;
    // 初始值不确定
    PrintElements(arr1, "no initialize:   ");

    array<int, 3> arr2 = {};
    // 初始值为0
    PrintElements(arr2, "initialize:   ");

    typedef array<string, 5> FiveStrings;
    FiveStrings arr3 = {"hello", "Jam", "how", "are", "you"};
    cout << tuple_size<FiveStrings>::value << endl;  // 5
    cout << get<1>(arr3).c_str() << endl;  // Jam

    array<int, 10> arr4 = {11, 22, 33, 44};
    PrintElements(arr4, "original:   ");

    arr4.back() = 9999;
    PrintElements(arr4, "modify:   ");

    cout << "sum:   "
        << accumulate(arr4.begin(), arr4.end(), 0)
        << endl;
    return 0;
}
