// Copyright 2017.刘珅珅
// author：刘珅珅
// 静态成员与继承
#include <iostream>

class Base
{
  public:
    static void func()
    {
        std::cout << "Base的静态函数" << std::endl;
    }

  protected:
    int number;
    static int num_sta;
};

int Base::num_sta = 99;

class Derive : public Base
{
  public:
    void f()
    {
        Base::func();
        Base::num_sta = 5;

        num_sta = 6;
        func();
    }

    static void func()
    {
        std::cout << "Derive的静态函数" << std::endl;
    }

  private:
    static int num_sta;

};

int Derive::num_sta = 0;

int main(int argc, char* argv[])
{
    Derive d;
    d.f();
    return 0;
}
