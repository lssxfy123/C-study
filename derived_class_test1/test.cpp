// Copyright 2016.���|�|
// author�����|�|
// ������̳л�����麯���ķ��ʿ���
#include <iostream>
using namespace std;

// �����麯��private��������Ϊpublic
class Base {
private:
    virtual void func()
    {
        cout << "Base::func()" << endl;
    }
};

class Derived : public Base {
public:
    virtual void func()
    {
        cout << "Derived::func()" << endl;
    }
};

// ����public��������private
class Base1 {
public:
    virtual void func1()
    {
        cout << "Base1::func1()" << endl;
    }
};

class Derived1 : public Base1 {
private:
    virtual void func1()
    {
        cout << "Derived1::func1()" << endl;
    }
};

int main(int argc, char* argv[])
{
    Derived d;
    Base& b = d;

    // error�������е��麯��Ϊprivate��
    // ��ʹ�������ض�����麯��Ϊpublic��
    // ���������Ҳ�޷����ø��麯��
    // �ڱ���ʱ�ͻᱨ��
    // b.func();
    d.func();

    Derived1 d1;
    Base1& b1 = d1;
    // ������Ϊ��Derived1::func1()
    // b1��ָ��Ķ���Ϊd1��
    // d1���麯�����д洢�ĺ���ָ��Ϊ
    // Derived1::func1()
    b1.func1();
    return 0;
}
