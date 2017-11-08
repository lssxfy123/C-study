// Copyright 2017.刘珅珅
// author：刘珅珅
// set和map容器的比较类型针对等价值的准则
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // 错误的例子
    set<int, less_equal<int>> set1;
    set1.insert(10);

    // error，抛出异常，比较函数在等值情况下返回true
    // set1.insert(10);

    map<int, int, less_equal<int>> map1;
    map1.insert({1, 2});

    // error，抛出异常
    //map1.insert(make_pair(1, 3));

    return 0;
}
