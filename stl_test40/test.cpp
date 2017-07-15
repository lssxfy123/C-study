// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数对象
#include <algorithm>
#include <deque>
#include <functional>
#include <list>
#include <iostream>
#include "print.hpp"
using namespace std;

// 函数对象
class AddValue
{
public:
    AddValue(int value) : value_(value)
    {}

    // 这个函数最好定义为const
    void operator() (int& elem) const {
        elem += value_;
    }
private:
    int value_;
};

int main(int argc, char* argv[])
{
    list<int> coll;
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    PrintElements(coll, "initialized:     ");

    // 函数对象作为算法的实参
    for_each(coll.begin(), coll.end(), AddValue(10));
    PrintElements(coll, "after adding 10:       ");

    // 一个函数，两个状态
    // 通过初始化不同的AddValue，呈现不同的状态
    for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
    PrintElements(coll, "after adding first element:    ");

    deque<int> coll1 = {1, 2, 3, 5, 7, 11, 13, 17, 19};
    PrintElements(coll1, "initialized:    ");
    transform(coll1.cbegin(), coll1.cend(), coll1.begin(), negate<int>());
    PrintElements(coll1, "negated:    ");

    transform(coll1.cbegin(), coll1.cend(), coll1.cbegin(),
        coll1.begin(), multiplies<int>());
    PrintElements(coll1, "squared:    ");
    return 0;
}
