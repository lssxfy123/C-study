// ���캯�������������е����麯��

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
    Derive d;  // ���Base::func()������Ĺ��캯�����õ��ǻ����func����
    return 0;
}
