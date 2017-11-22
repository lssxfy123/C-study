// Copyright 2017.刘珅珅
// author：刘珅珅
// 虚函数与默认实参
#include <iostream>

class Base
{
  public:
    virtual void func(char* name = "base")
    {
        std::cout << "调用基类Base的func()函数" << name << std::endl;
    }
};

class Derive : public Base
{
  public:
    void func(char* name = "derive")
    {
        std::cout << "调用派生类Dervie的func()函数" << name << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Derive derive;
    Base* b_ptr = &derive;

    b_ptr->func();  // 调用了派生类的虚函数，但是默认的形参值却是基类的，原因是默认形参的值是在编译时就确定好的.
    return 0;
}

