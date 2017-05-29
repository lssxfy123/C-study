// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11返回右值引用
#include <iostream>
using namespace std;

class P
{
public:
    P() : length_(10), ptr_(new int[length_])
    {
        cout << "default constructor" << endl;
        for (int i = 0; i < length_; ++i)
        {
            ptr_[i] = i;
        }
    }

    P(const P& p) : length_(p.length_)
    {
        cout << "copy constructor" << endl;
        ptr_ = new int[length_];
        for (int i = 0; i < length_; ++i)
        {
            ptr_[i] = p.ptr_[i];
        }
    }

    P(P&& p) : length_(p.length_), ptr_(p.ptr_)
    {
        cout << "P&& constructor" << endl;
        p.ptr_ = nullptr;
    }

    ~P()
    {
        cout << "~P()" << endl;
        if (ptr_)
        {
            delete[] ptr_;
        }
        
        ptr_ = nullptr;
    }

private:
    int length_;
    int* ptr_;
};

P& Func1()
{
    P p;
    P& rp = p;
    return rp;
}

P&& Func2()
{
    P p;
    return move(p);
}

int main(int argc, char* argv[])
{
    // error,Func1()返回引用
    // 但p是一个局部变量，返回左值引用rp所引用的对象
    // 会马上析构掉，p1的拷贝构造函数传入的是
    // 一个已析构的对象
    //P p1(Func1());

    // error，Func2()将局部变量p从左值变成右值引用
    // 右值引用也是引用，会和上述的左值引用出现同样的问题
    //P p2(Func2());
    return 0;
}
