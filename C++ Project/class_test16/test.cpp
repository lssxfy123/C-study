// Copyright 2017.刘珅珅
// author：刘珅珅
// 覆盖虚函数机制
#include <iostream>

class Base
{
  public:
    virtual void func()
    {
        number = 5;
        std::cout << "number = " << number << std::endl;
    }

  private:
    int number;
};

class Derive : public Base
{
  public:
    void func()
    {
        Base::func();
        count = 10;
        std::cout << "count = " << count << std::endl;
    }

  private:
    int count;
};

int main(int argc, char* argv[])
{
    Derive derive;
    Base* b_ptr = &derive;

    // b_ptr->Base::func();  // 调用基类Base的func()函数，通过作用域操作符::覆盖了虚函数机制
    b_ptr->func();
    return 0;
}
