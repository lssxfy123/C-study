// Copyright 2017.���|�|
// author�����|�|
// ����������
#include <iostream>
using std::cout;
using std::endl;

class Base
{
  public:
    int m_a;

    Base(int a = 2) : m_a(a)
    {
        cout << "A " << m_a << endl;
    }

    virtual ~Base()
    {
        cout << "B " << m_a << endl;
    }
};

class Derived : public Base
{
  public:
    Derived(int a = 4) : Base(a)
    {
        cout << "C " << m_a << endl;
    }

    ~Derived()
    {
        cout << "D " << m_a << endl;
    }
};

int main(void)
{
    // ����Base *aa������ù��캯��
    Base *aa, bb;
    aa = new Derived;
    delete aa;

    return 0;
}
