// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数适配器
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <iostream>
#include <set>
#include "../include/print.hpp"
using namespace std;
using namespace std::placeholders;

int main(int argc, char* argv[])
{
    set<int, greater<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> coll2;
    PrintElements(coll1, "initialized: ");

    // 将coll1所有元素乘以10传递到coll2中
    // bind(multiplies<int>(), _1, 10)是一个函数对象
    // 由 低层的函数对象multiplies<int>()和占位符_1合成
    transform(coll1.cbegin(), coll1.cend(),  // source：源
        back_inserter(coll2),  // destination：目标
        bind(multiplies<int>(), _1, 10));  // operation：操作
    PrintElements(coll2, "transformed: ");

    // 替换coll2中值为70的元素为42
    // bind(equal_to<int>(), _1, 70)是一个合成的函数对象
    replace_if(coll2.begin(), coll2.end(), 
        bind(equal_to<int>(), _1, 70), 
        42);
    PrintElements(coll2, "replaced:    ");

    // 移除x>=50 && x<=80
    // bind()可以用来描述复杂的判断式
    //logical_and, greater_equal, less_equal都是struct结构体
    // 都提供了operator()重载， 所以都是函数对象
    coll2.erase(remove_if(coll2.begin(), coll2.end(), 
        bind(logical_and<bool>(),
        bind(greater_equal<int>(), _1, 50),
        bind(less_equal<int>(), _1, 80))), 
        coll2.end());
    PrintElements(coll2, "removed:    ");
    return 0;
}
