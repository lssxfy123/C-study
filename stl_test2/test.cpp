// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11新特性1
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    // C++11中两个左括号之间没了空格
    vector<list<int>> vec;

    // 空指针
    int* ptr = nullptr;

    auto i = 43;
    cout << typeid(i).name() << endl;  // int

    vector<string> strVec;
    strVec.push_back("start");
    auto begin = strVec.begin();
    cout << typeid(begin).name() << endl;

    // 一致性初始化，跟C#的赋值方式类似
    int k;  // 未初始化
    int j{};  // 初始化为0
    int* q{};  // 初始化为nullptr
    cout << j << endl; // 0
    int values[] {1, 2, 3};  // 1,2,3
    vector<int> v{ 2, 3, 5, 7 };
    cout << v.size() << endl;  // 4

    int x1{ 5 };  // x1初始化为5
    int x2 = 5.3;  // x2为5，精度降低了

    // 一致性初始化{}不能用于窄化
    // 即精度降低或数值变动
    //int x3{ 5.3 };  // error

    double d1{ 5 };  // ok
    return 0;
}
