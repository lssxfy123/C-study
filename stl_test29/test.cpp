// Copyright 2017.刘珅珅
// author：刘珅珅
// stl标准模板库：序列式容器(Container)
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class A {
public:
    A()
    {
        cout << "construct A" << endl;
    }

    A(const A& rhs)
    {
        cout << "copy construct A" << endl;
    }
};

int main(int arg, char* argv[])
{
    // 双向队列
    deque<float> coll;
    for (int i = 1; i <= 6; ++i)
    {
        coll.push_front(i * 1.1f);
    }

    for (auto f : coll)
    {
        cout << f << ' ';
    }
    cout << endl;

    for (int j = 1; j <= 6; ++j)
    {
        coll.push_back(j * 1.1f);
    }

    for (auto f : coll)
    {
        cout << f << ' ';
    }
    cout << endl;

    // array
    // 可以使用初值列表进行初始化
    array<string, 5> coll_array = {"hello", "world"};
    for (array<string, 5>::size_type i = 0; i < coll_array.size(); ++i)
    {
        cout << i << ": " << coll_array[i].c_str() << endl;
    }

    // list<>
    list<char> coll_list1;
    list<char> coll_list2;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        coll_list1.push_back(c);
        coll_list2.push_back(c);
    }

    // 打印链表中的所有元素
    for (const auto& elem : coll_list1)
    {
        cout << elem << ' ';
    }
    cout << endl;

    // 打印链表中的元素并移除第一个元素
    while (!coll_list2.empty())
    {
        cout << coll_list2.front() << ' ';
        coll_list2.pop_front();  // 移除首元素
    }
    cout << endl;
    return 0;
}
