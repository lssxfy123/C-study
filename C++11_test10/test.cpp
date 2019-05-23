// Copyright 2017.刘珅珅
// author：刘珅珅
// 移动语义
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class Test
{
public:
    Test() : ptr_(new int(3))
    {
        cout << "Construct address: "<< hex << this << endl;
    }

    Test(Test& t) : ptr_(new int(*t.ptr_))
    {
        cout << "Copy construct from address: " << hex << &t << " to address: " << this << endl;

    }

    Test& operator=(Test& t)
    {
        cout << "Assign: " << endl;
        if (ptr_ != nullptr)
            delete ptr_;
        ptr_ = new int(*t.ptr_);
        return *this;
    }

    //Test(Test&& t) : ptr_(t.ptr_)
    //{
    //    t.ptr_ = nullptr;
    //    cout << "Move construct: " << endl;
    //}

    ~Test()
    {
        delete ptr_;
        ptr_ = nullptr;
        cout << "Destruct address: " << this << endl;
    }

public:
    int* ptr_;
};

Test GetTest() {
    Test t;
    return t;
}

Test GetTest1()
{
    return Test();
}

int main(int argc, char* argv[])
{
    cout << "call function GetTest() start." << endl;
    GetTest();
    cout << "call function GetTest() end." << endl;

    cout << endl;
    cout << "call function GetTest() start 2." << endl;
    Test t1;
    t1 = GetTest();  // 调用赋值运算符
    cout << endl;
    Test t3 = GetTest();
    cout << "call function GetTest() end 2." << endl;
    cout << "t1 address: " << &t1 << endl;
    cout << endl;

    cout << "call function GetTest1() start." << endl;
    GetTest1();
    cout << "call function GetTest1() end." << endl;
    cout << endl;

    cout << "call function GetTest1() start 2." << endl;
    Test t2 = GetTest1();
    cout << "t2 address: " << hex << &t2 << endl;
    cout << "call function GetTest1() end 2." << endl;
    cout << endl;

    return 0;
}
