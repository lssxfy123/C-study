// Copyright 2017.���|�|
// author�����|�|
// ���麯����ͬ���ᴥ����̬��
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
    b.f();  // ���麯��Ҳ�ᴥ����̬��
    return 0;
}
