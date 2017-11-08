// Copyright 2017.���|�|
// author�����|�|
// new������ָ�����STL����
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

// ����ִ����󣬲������Test����������
// ������ڴ�й©
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
