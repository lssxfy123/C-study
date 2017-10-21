// Copyright 2017.刘珅珅
// author：刘珅珅
// 继承中的拷贝构造和移动构造
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class Base {
public:
    Base(int number) : number_(number)
    {
        cout << "Construct Base" << endl;
    }

    Base(const Base& org) : number_(org.number_)
    {
        cout << "Copy construct Base" << endl;
    }

    Base(Base&& org) : number_(org.number_)
    {
        cout << "Move construct Base" << endl;
    }

    virtual ~Base()
    {
        cout << "Destruct Base" << endl;
    }

private:
    int number_;
};

class Derived : Base
{
public:
    Derived(int no) : Base(no), no_(no)
    {
        cout << "Construct Derived" << endl;
    }

    Derived(const Derived& org) : Base(org), no_(org.no_)
    {
        cout << "Copy construct Derived" << endl;
    }

    Derived(Derived&& org) : Base(std::move(org)), no_(org.no_)
    {
        cout << "Move construct Derived" << endl;
    }

    ~Derived()
    {
        cout << "Destruct Derived" << endl;
    }

private:
    int no_;
};

int main(int argc, char* argv[])
{
    Derived d1(3);
    cout << endl;

    Derived d2(d1);
    cout << endl;

    Derived d3(move(d1));
    cout << endl;
    return 0;
}
