// Copyright 2017.���|�|
// author�����|�|
// �麯����override��final�����
#include <iostream>
#include "../include/print.hpp"
using namespace std;

// ����
class Base
{
public:
    virtual void F1(int) const
    {}

    virtual void F2()
    {}

    void F3()
    {}
};

class Derived : Base {
public:
    void F1(int) const override  // ok���������麯��F1ƥ��
    {}

    void F2() override  // ok���������麯��F2ƥ��
    {}

    // error������û������ΪF3()���麯��
    //void F3() override
    //{}
};

class Derived2 : Base
{
public:
    void F1(int) const final  // ���������������า��F1
    {}
};

class Derived3 : Derived2
{
public:
    // error��Derived2��F1()����Ϊfinal
    //void F1(int) const
    //{}
    void F2()  // ok�����Ǽ�ӻ���Base�̳е�F2
    {}
};

int main(int argc, char* argv[])
{
    return 0;
}
