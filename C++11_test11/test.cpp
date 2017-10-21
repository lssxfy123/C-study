// Copyright 2017.刘珅珅
// author：刘珅珅
// std::move
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class Moveable
{
public:
    Moveable() : ptr_(new int(3))
    {
        cout << "Construct Moveable" << endl;
    }

    // 拷贝构造函数
    Moveable(const Moveable& org) : ptr_(new int(*org.ptr_))
    {
        cout << "Copy construct Moveable" << endl;
    }

    // 移动构造函数
    Moveable(Moveable&& org) : ptr_(org.ptr_)
    {
        cout << "Move construct Moveable" << endl;
        org.ptr_ = nullptr;
    }

    ~Moveable()
    {
        if (ptr_ != nullptr)
        {
            cout << "delete ptr_" << endl;
            delete ptr_;
            ptr_ = nullptr;
        }
    }

    // 移动赋值运算符
    Moveable& operator=(Moveable&& org)
    {
        if (this != &org)
        {
            cout << "Move operator=" << endl;
            delete ptr_;
            ptr_ = org.ptr_;
            org.ptr_ = nullptr;
        }
        return *this;
    }

public:
    int* ptr_;
};

int main(int argc, char* argv[])
{
    int c = 0;
    // int&& rr1 = c;  // error，右值引用不能绑定左值
    int&& rr1 = std::move(c);  // ok，move()将左值c强制转换为右值

    {
        Moveable m;
        Moveable m1(m);
    }

    cout << endl;

    {
        Moveable m;
        Moveable m2(std::move(m));

        // error，抛出异常
        // 对象m中的指针ptr_的内存已被移动给了m2
        // cout << *m.ptr_ << endl;
    }

    cout << endl;
    {
        Moveable m;
        Moveable m3;
        m3 = std::move(m);
    }
    return 0;
}
