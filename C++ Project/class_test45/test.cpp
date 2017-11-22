// Copyright 2017.刘珅珅
// author：刘珅珅
// inline函数与虚函数
#include<iostream>
using namespace std;

class A
{
  public:
    inline virtual void virFUn()
    {
        cout << "我是A中虚函数，inline在这不起作用！" << endl;
    }
    void f();

    // virtual static void func();  // error，静态函数不能为虚函数

};

inline void A::f()
{
    cout << "我是真正的内联函数，不能同时设置为虚函数！" << endl;
}


class B : public A
{
  public:
    virtual void virFUn() 
    {
        cout << "我是B中虚函数！" << endl;
    }
};

int main(int argc, char* argv[])
{
    B b;
    b.virFUn();
    A a;
    a.f();
    return 0;
}
