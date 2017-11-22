// Copyright 2017.���|�|
// author�����|�|
// �麯����̬�󶨵Ĵ���
#include <iostream>
using std::cout;
using std::endl;

class Base
{
  public:
    int m_a,m_b;

    Base(int a = 2, int b = 5) : m_a(a), m_b(b)  {  }

    int func_a()
    {
        return m_a - m_b;
    }

    virtual int func_b()
    {
        return m_a + m_b;
    }
};

class Derived:public Base
{
  public:
    Derived(int a = 4, int b = 7) : Base(a, b)  {  }

    virtual int func_a()  // ���ṹ�ɶ�̬�󶨣�������δ����Ϊ�麯��
    {
        return m_b + m_a;
    }

    int func_b()
    {
        return m_b - m_a;
    }
};

int main(void)
{
    Base *aa, *bb;
    aa = new Base(4, 7);
    bb = new Derived(3, 5);

    cout << aa->func_a() << " " << aa->func_b() << " " << bb->func_a()<< " " << bb->func_b() << endl;

    delete aa;
    delete bb;
    return 0;
}
