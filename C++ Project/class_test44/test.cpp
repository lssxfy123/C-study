// 构造函数和析构函数中调用虚函数

#include <iostream>
using std::cout;
using std::endl;

class Base
{
  public:
    Base();
    ~Base();

  public:
    virtual void func();
};

Base::Base()
{
    func();
}

Base::~Base()
{

}

void Base::func()
{
    cout << "Base::func()" << endl;
}

class Derive : public Base
{
  public:
    Derive();
    ~Derive();

  public:
    void func();
};

Derive::Derive()
{

}

Derive::~Derive()
{

}

void Derive::func()
{
    cout << "Dervie::func()" << endl;
}

int main(int argc, char* argv[])
{
    Derive d;  // 输出Base::func()，基类的构造函数调用的是基类的func函数
    return 0;
}
