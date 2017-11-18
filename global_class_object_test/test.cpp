// Copyright 2017.刘珅珅
// author：刘珅珅
// 类对象测试
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class A {
public:
    A();
    A(const A& a);
    A(string name);
    ~A();

    void Print();

public:
    A& operator=(const A& org);

private:
    string name_;
};

A::A()
{
    cout << "construct null" << endl;
}

A::A(string name) : name_(name)
{
    cout << "construct with name " << name << endl;
}

A::A(const A& a) : name_(a.name_)
{
    cout << "copy construct from name " << a.name_ << endl;
}

A::~A()
{
    cout << "destructor " << name_ << endl;
}

A& A::operator=(const A& org)
{
    cout << "operator = A" << endl;
    name_ = org.name_;
    return *this;
}

void A::Print()
{
    cout << "name is " << name_ << endl;
}

// 在main函数之前调用构造函数
A a;

int main()
{
    cout << "start main" << endl;

    // =右边的构造函数执行，语句结束后就会执行析构函数
    // 因为其产生的是临时对象（右值），类A需要重载operator=
    // 并将临时对象的内容传递给对象a，否则对象a无法使用
    // 临时对象初始化的name_
    a = A("teatcher");
    a.Print();
    int b = 0;

    A a1;
    a1 = A("student");
    a1.Print();
    a1 = A("user");
    a1.Print();
    int c = 0;

    return 0;
}
