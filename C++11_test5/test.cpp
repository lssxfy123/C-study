// Copyright 2017.刘珅珅
// author：刘珅珅
// 新的构造函数
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class Test {
public:
    // 使用默认构造函数
    Test() = default;
};

class Test1
{
public:
    Test1(string no, int count) : book_no_(no), count_(count)
    {
        cout << "constructor Test1(string no, int count)" << endl;
    }

    // 委托构造函数
    // 初始化列表只能是被委托的构造函数
    // 不能有其他的初始化操作
    Test1() : Test1("", 0)
    {
        cout << "default constructor" << endl;
    }

    Test1(string no) : Test1()
    {
        cout << "constructor Test1(string no)" << endl;
        cout << no << " is not used" << endl;
    }

private:
    string book_no_;
    int count_;
};

class Test2
{
public:
    // constexpr必须初始化所有的成员变量
    // 初始化值是一条常量表达式或constexpr
    // 构造函数（针对某些类类型的成员变量）
    constexpr Test2(bool hw, bool io, bool other)
        : hw_(hw), io_(io), other_(other)
    {

    }
private:
    bool hw_;
    bool io_;
    bool other_;
};

int main(int argc, char* argv[])
{
    Test t;

    // 委托构造
    Test1 t1;
    cout << endl;
    Test1 t2("1234");
    return 0;
}
