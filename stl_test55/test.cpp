// Copyright 2017.刘珅珅
// author：刘珅珅
// 迭代器
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll;
    coll.push_back(9);
    coll.push_back(3);
    coll.push_back(0);
    coll.push_back(8);
    coll.push_back(5);

    // 将容器coll从第2个开始排序
    if (coll.size() > 1)
    {
        // 这种写法在visual studio可以编译通过
        // 但不具备可移植性，因为有可能在其他平台上
        // 编译不通过
        // sort(++coll.begin(), coll.end());
    }

    if (coll.size() > 1)
    {
        // 可移植的写法
        sort(next(coll.begin()), coll.end());
    }

    for (const auto& elem : coll)
    {
        cout << elem << " ";
    }
    cout << endl;

    // advance
    list<int> coll_list;
    for (int i = 1; i <= 9; ++i)
    {
        coll_list.push_back(i);
    }
    list<int>::iterator pos = coll_list.begin();
    cout << "step three elements forward:" << endl;
    advance(pos, 3);
    cout << *pos << endl;
     
    cout << "step one element backward: " << endl;
    advance(pos, -1);
    cout << *pos << endl;

    // 运行时会报内存错误
    // pos越界了
    // advance(pos, 9);

    // distance
    list<int> coll1;
    for (int i = -3; i <= 9; ++i)
    {
        coll1.push_back(i);
    }

    list<int>::iterator pos1 = find(coll1.begin(), coll1.end(), 5);
    list<int>::iterator pos2 = find(coll1.begin(), coll1.end(), 8);
    // 如果pos2在pos1之前会发生内存错误
    //list<int>::iterator pos2 = find(coll1.begin(), coll1.end(), 4);
    if (pos1 != coll1.end() && pos2 != coll1.end())
    {
        iterator_traits<list<int>::iterator>::difference_type n = distance(pos1, pos2);
        cout << "difference between 5 and 8 is " << n << endl;
    }
    cout << endl;

    // iter_swap
    PrintElements(coll1);
    cout << "swap begin and next(begin): " << endl;
    iter_swap(coll1.begin(), next(coll1.begin()));
    PrintElements(coll1);
    return 0;
}
