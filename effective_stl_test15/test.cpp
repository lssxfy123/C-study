// Copyright 2017.刘珅珅
// author：刘珅珅
// STL算法的调用优先于循环
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include "../include/print.hpp"
using namespace std;

class Test
{
public:

    void Print() const
    {
        cout << "Print Test" << endl;
    }
};

int main(int argc, char* argv[])
{
    Test t1;
    Test t2;
    Test t3;
    list<Test> list1;
    list1.push_back(t1);
    list1.push_back(t2);
    list1.push_back(t3);

    //  循环调用Print
    //for_each(list1.begin(), list1.end(), std::mem_fn(&Test::Print));
    for_each(list1.begin(), list1.end(), std::bind(&Test::Print, std::placeholders::_1));
    return 0;
}
