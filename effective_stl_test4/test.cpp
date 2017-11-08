// Copyright 2017.刘珅珅
// author：刘珅珅
// vector和string容器的内存重新分配
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

class Test
{
public:
    Test(string name) : name_(name)
    {
        cout << "Construct Test " << name_ << endl;
    }

    Test(const Test& org) : name_(org.name_)
    {
        cout << "Copy construct Test " << name_ << endl;
    }

    virtual ~Test()
    {
        cout << "Destruct Test " << name_ << endl;
    }

private:
    string name_;
};

int main(int argc, char* argv[])
{
    Test t1("1");
    Test t2("2");
    Test t3("3");
    cout << endl;

    vector<Test> vec;
    cout << "first push" << endl;
    vec.push_back(t1);
    cout << "vector size = " << vec.size() << " capacity = " << vec.capacity() << endl;
    cout << endl;
    cout << "second push" << endl;
    vec.push_back(t2);
    cout << "vector size = " << vec.size() << " capacity = " << vec.capacity() << endl;
    cout << endl;
    cout << "third push" << endl;
    vec.push_back(t3);
    cout << "vector size = " << vec.size() << " capacity = " << vec.capacity() << endl;
    cout << endl;

    // 使用reserve减少内存重分配
    vector<Test> vec1;
    vec1.reserve(3);
    vec1.push_back(t1);
    vec1.push_back(t2);
    vec1.push_back(t3);
    cout << endl;
    return 0;
}
