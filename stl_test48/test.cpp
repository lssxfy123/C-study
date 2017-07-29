// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：set和multiset
#include <algorithm>
#include <functional>
#include <set>
#include <iostream>
#include <iterator>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    set<int> coll1;
    coll1.insert(1);
    coll1.insert(2);
    coll1.insert(4);
    coll1.insert(5);
    coll1.insert(6);

    // 返回第1个可以安插值为3的元素的位置
    cout << "lower_bound(3): " << *coll1.lower_bound(3) << endl;
    // 返回最后一个可以安插值为3的元素的位置
    cout << "upper_bound(3): " << *coll1.upper_bound(3) << endl;
    // 返回第1个和最后1个可以安插值为3的元素的区间
    cout << "equal_range(3): " << *coll1.equal_range(3).first 
        << "  " << *coll1.equal_range(3).second << endl;

    cout << endl;
    cout << "lower_bound(5): " << *coll1.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *coll1.upper_bound(5) << endl;
    cout << "equal_range(5): " << *coll1.equal_range(5).first
        << "  " << *coll1.equal_range(5).second << endl;

    cout << endl;

    // 从大到小排序
    set<int, greater<int>> coll2;
    coll2.insert({4, 3, 5, 1, 6, 2});
    for (auto elem : coll2)
    {
        cout << elem << ' ';
    }
    cout << endl;
    auto status = coll2.insert(4);
    if (status.second)
    {
        cout << "4 inserted as element " << distance(coll2.begin(), status.first) + 1 << endl;
    }
    else {
        cout << "4 already exists" << endl;
    }

    // 从小到大排序
    set<int> coll3(coll2.cbegin(), coll2.cend());
    copy(coll3.cbegin(), coll3.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // 删除从开头到元素3的位置所有的元素
    coll3.erase(coll3.begin(), coll3.find(3));

    int num = coll3.erase(5);
    cout << num << " element(s) removed" << endl;
    copy(coll3.cbegin(), coll3.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
