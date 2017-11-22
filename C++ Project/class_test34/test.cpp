// Copyright 2017.刘珅珅
// author：刘珅珅
// 类继承中构造函数的调用
#include <iostream>

class Base
{
  public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    ~Base()
    {

    }
};

class Derive : public Base
{
  public:
    Derive()
    {
        std::cout << "Derive()" << std::endl;
    }

    ~Derive()
    {

    }
};

int main(int argc, char* argv[])
{
    Base* b_ptr = NULL; // 定义指针不会调用构造函数

    b_ptr = new Derive();
    delete b_ptr;
    b_ptr = NULL;

    Derive d;
    Base& b_ref = d;  // 定义引用不会调用构造函数

    return 0;
}
