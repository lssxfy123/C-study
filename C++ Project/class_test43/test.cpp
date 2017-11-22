// Copyright 2017.刘珅珅
// author：刘珅珅
// 纯虚函数：同样会触发动态绑定
#include <iostream>
using std::cout;
using std::endl;

class Base
{
  public:
    virtual void f() = 0;
};

class Derive : public Base
{
  public:
    void f()
    {
        cout << "Derive::f()" << endl;
    }
};

int main(int argc, char* argv[])
{
    Derive d;
    Base& b = d;
    b.f();  // 纯虚函数也会触发动态绑定
    return 0;
}
