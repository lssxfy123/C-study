// Copyright 2017.���|�|
// author�����|�|
// inline�������麯��
#include<iostream>
using namespace std;

class A
{
  public:
    inline virtual void virFUn()
    {
        cout << "����A���麯����inline���ⲻ�����ã�" << endl;
    }
    void f();

    // virtual static void func();  // error����̬��������Ϊ�麯��

};

inline void A::f()
{
    cout << "������������������������ͬʱ����Ϊ�麯����" << endl;
}


class B : public A
{
  public:
    virtual void virFUn() 
    {
        cout << "����B���麯����" << endl;
    }
};

int main(int argc, char* argv[])
{
    B b;
    b.virFUn();
    A a;
    a.f();
    return 0;
}
