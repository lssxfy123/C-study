// Copyright 2017.刘珅珅
// author：刘珅珅
// STL容器的拷贝
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Construct Base" << endl;
    }

    Base(const Base& org)
    {
        cout << "Copy construct Base" << endl;
    }

    virtual ~Base()
    {
        cout << "Destruct Base" << endl;
    }

    virtual void Print()
    {
        cout << "Print Base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Construct Derived" << endl;
    }

    Derived(const Derived& org) : Base(org)
    {
        cout << "Copy construct Derived" << endl;
    }

    ~Derived()
    {
        cout << "Destruct Derived" << endl;
    }

    void Print() override
    {
        cout << "Print Derived" << endl;
    }
};

int main(int argc, char* argv[])
{
    cout << "Original Object" << endl;
    Base b;
    vector<Base> base_vector;
    cout << endl;
    cout << "Push in vector" << endl;
    base_vector.push_back(b);

    cout << endl;
    cout << "Get from vector" << endl;
    Base b1 = base_vector[0];
    cout << endl;

    cout << "Original Derived Object" << endl;
    Derived d;
    vector<Base> base_vector1;
    cout << endl;
    cout << "Push in Base vector" << endl;
    // 这里只会调用基类的拷贝构造函数
    // 将派生类对象的基类部分拷贝进容器
    base_vector1.push_back(d);
    cout << endl;

    cout << "Call virtual function" << endl;
    base_vector1[0].Print();
    cout << endl;

    return 0;
}
