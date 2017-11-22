// Copyright 2017.���|�|
// author�����|�|
// ��̬��Ա��̳�
#include <iostream>

class Base
{
  public:
    static void func()
    {
        std::cout << "Base�ľ�̬����" << std::endl;
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
        std::cout << "Derive�ľ�̬����" << std::endl;
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
