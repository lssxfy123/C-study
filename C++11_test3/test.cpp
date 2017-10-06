// Copyright 2017.刘珅珅
// author：刘珅珅
// 范围for语句
#include <cctype>
#include <iostream>
#include "../include/print.hpp"
using namespace std;

void Func(int(& arr)[5])
{
    // 必须是数组的引用才能使用begin和end
    for (auto p = begin(arr); p != end(arr); ++p)
    {
        cout << *p << " ";
    }
}

int main(int argc, char* argv[])
{
    string str{"some string!!!"};
    decltype(str.size()) punct_count = 0;

    // 范围for语句
    // 统计标点符号
    for (auto c : str)
    {
        if (ispunct(c))
        {
            ++punct_count;
        }
    }
    cout << punct_count
        << " punctuation characters in " << str << endl;

    // 范围for语句中修改字符
    // 采用引用
    for (auto& c : str)
    {
        c = toupper(c);
    }
    cout << "Upper characters " << str << endl;

    // for语句使用下标修改字符
    for (decltype(str.size()) index = 0; index != str.size(); ++index)
    {
        str[index] = tolower(str[index]);
    }

    for (decltype(str.size()) index = str.size() - 1; index >= 0 && index < str.size(); --index)
    {
        str[index] = tolower(str[index]);
    }
    cout << "Lower characters " << str << endl;

    // 访问普通的数组
    int arr[5] = {1, 2, 3, 4, 5};

    // begin和end无法判断通过new创建的数组
    for (auto p = begin(arr); p != end(arr); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
