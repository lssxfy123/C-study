// Copyright 2017.刘珅珅
// author：刘珅珅
// 多重继承构造顺序
#include <iostream>
using namespace std;

class OBJ
{
  public:
    OBJ()
    {
        cout << "OBJ\n";
    }
};

class Base1
{
  public:
    Base1()
    {
        cout << "Base1\n";
    }
};

class Base2 : virtual public Base1
{
  public:
    Base2()
    {
        cout << "Base2\n";
    }
};

class Base3
{
  public:
    Base3()
    {
        cout << "Base3\n";
    }
};

class Base4
{
  public:
    Base4()
    {
        cout << "Base4\n";
    }
};

class Derived : public Base2, public Base3, virtual public Base4
{
  public:
    Derived()
    {
        cout << "Derived\n";
    }

  protected:
    OBJ obj;
};

int main(int argc, char* argv[])
{
    Derived d;
}
