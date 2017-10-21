// Copyright 2017.刘珅珅
// author：刘珅珅
// 虚函数的override和final运算符
#include <iostream>
#include "../include/print.hpp"
using namespace std;

// 基类
class Base
{
public:
    virtual void F1(int) const
    {}

    virtual void F2()
    {}

    void F3()
    {}
};

class Derived : Base {
public:
    void F1(int) const override  // ok，与基类的虚函数F1匹配
    {}

    void F2() override  // ok，与基类的虚函数F2匹配
    {}

    // error，基类没有名称为F3()的虚函数
    //void F3() override
    //{}
};

class Derived2 : Base
{
public:
    void F1(int) const final  // 不允许后序的派生类覆盖F1
    {}
};

class Derived3 : Derived2
{
public:
    // error，Derived2中F1()声明为final
    //void F1(int) const
    //{}
    void F2()  // ok，覆盖间接基类Base继承的F2
    {}
};

int main(int argc, char* argv[])
{
    return 0;
}
