// Copyright 2017.刘珅珅
// author：刘珅珅
// stl容器算法：Algorithm
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll = { 2, 5, 4, 1, 6, 3};
    auto min_pos = min_element(coll.cbegin(), coll.cend());
    cout << "min: " << *min_pos << endl;
    auto max_pos = max_element(coll.cbegin(), coll.cend());
    cout << "max: " << *max_pos << endl;

    // 排序
    sort(coll.begin(), coll.end());
    for (const auto& elem : coll)
    {
        cout << elem << ' ';
    }
    cout << endl;

    // 找到第一个值为3的元素
    auto pos3 = find(coll.begin(), coll.end(), 3);

    // 反序
    // 将查找到的值为3的元素及之后的元素反序
    reverse(pos3, coll.end());
    for (const auto& elem : coll)
    {
        cout << elem << ' ';
    }
    cout << endl;

    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> coll2;
    // 需要提前分配空间
    coll2.resize(coll1.size());
    // 默认的迭代器下copy以覆盖方式而非插入方式运作
    copy(coll1.cbegin(), coll1.cend(), coll2.begin());
    for (const auto& elem : coll2)
    {
        cout << elem << ' ';
    }
    cout << endl;
    return 0;
}
