// Copyright 2017.刘珅珅
// author：刘珅珅
// new创建的指针存入STL容器
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include "../include/print.hpp"
using namespace std;

class Test
{
public:
    ~Test()
    {
        cout << "Destruct Test" << endl;
    }
};

// 函数执行完后，不会调用Test的析构函数
// 会造成内存泄漏
void DoSomething()
{
    Test* ptr = new Test();
    vector<Test*> vec1;
    vec1.push_back(ptr);
}

struct DeleteObject
{
    template<typename T>
    void operator() (const T* ptr) const
    {
        delete ptr;
    }
};

void DoSomething1()
{
    Test* ptr = new Test();
    vector<Test*> vec1;
    vec1.push_back(ptr);
    for_each(vec1.begin(), vec1.end(), DeleteObject());
}

void DoSomething2()
{
    typedef shared_ptr<Test> SPTest;
    Test* ptr = new Test();
    SPTest smart(ptr);
    vector<SPTest> vec1;
    vec1.push_back(smart);
}

int main(int argc, char* argv[])
{
    //DoSomething();
    // DoSomething1();
    DoSomething2();
    return 0;
}
