// Copyright 2017.���|�|
// author�����|�|
// ��������
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class A {
public:
    A();
    A(const A& a);
    A(string name);
    ~A();

    void Print();

public:
    A& operator=(const A& org);

private:
    string name_;
};

A::A()
{
    cout << "construct null" << endl;
}

A::A(string name) : name_(name)
{
    cout << "construct with name " << name << endl;
}

A::A(const A& a) : name_(a.name_)
{
    cout << "copy construct from name " << a.name_ << endl;
}

A::~A()
{
    cout << "destructor " << name_ << endl;
}

A& A::operator=(const A& org)
{
    cout << "operator = A" << endl;
    name_ = org.name_;
    return *this;
}

void A::Print()
{
    cout << "name is " << name_ << endl;
}

// ��main����֮ǰ���ù��캯��
A a;

int main()
{
    cout << "start main" << endl;

    // =�ұߵĹ��캯��ִ�У���������ͻ�ִ����������
    // ��Ϊ�����������ʱ������ֵ������A��Ҫ����operator=
    // ������ʱ��������ݴ��ݸ�����a���������a�޷�ʹ��
    // ��ʱ�����ʼ����name_
    a = A("teatcher");
    a.Print();
    int b = 0;

    A a1;
    a1 = A("student");
    a1.Print();
    a1 = A("user");
    a1.Print();
    int c = 0;

    return 0;
}
