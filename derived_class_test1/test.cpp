// Copyright 2016.刘珅珅
// author：刘珅珅
// 派生类继承基类的虚函数的访问控制
#include <iostream>
using namespace std;

// 基类虚函数private，派生类为public
class Base {
private:
    virtual void func()
    {
        cout << "Base::func()" << endl;
    }
};

class Derived : public Base {
public:
    virtual void func()
    {
        cout << "Derived::func()" << endl;
    }
};

// 基类public，派生类private
class Base1 {
public:
    virtual void func1()
    {
        cout << "Base1::func1()" << endl;
    }
};

class Derived1 : public Base1 {
private:
    virtual void func1()
    {
        cout << "Derived1::func1()" << endl;
    }
};

int main(int argc, char* argv[])
{
    Derived d;
    Base& b = d;

    // error，基类中的虚函数为private，
    // 即使派生类重定义的虚函数为public，
    // 基类的引用也无法调用该虚函数
    // 在编译时就会报错
    // b.func();
    d.func();

    Derived1 d1;
    Base1& b1 = d1;
    // 输出结果为：Derived1::func1()
    // b1所指向的对象为d1，
    // d1的虚函数表中存储的函数指针为
    // Derived1::func1()
    b1.func1();
    return 0;
}
