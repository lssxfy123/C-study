// Copyright 2017.刘珅珅
// author：刘珅珅
// 迭代器适配器：插入式迭代器适配器
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> coll2;
    // 插入容器末端
    // 在内部调用push_back执行插入
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
    for (const auto& elem : coll2)
    {
        cout << elem << ' ';
    }
    cout << endl;

    //vector<int> coll3;  // error，vector不能执行push_front操作
    deque<int> coll3;
    // 插入容器前端
    // 在内部执行push_front操作
    copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));
    for (const auto& elem : coll3)
    {
        cout << elem << ' ';
    }
    cout << endl;

    set<int> coll4;
    // 一般性插入，内部调用insert()插入
    // 可以用于关联式容器和无序容器
    copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.begin()));
    for (const auto& elem : coll4)
    {
        cout << elem << ' ';
    }
    cout << endl;
    return 0;
}
