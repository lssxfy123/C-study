// Copyright 2017.���|�|
// author�����|�|
// �麯����Ĭ��ʵ��
#include <iostream>

class Base
{
  public:
    virtual void func(char* name = "base")
    {
        std::cout << "���û���Base��func()����" << name << std::endl;
    }
};

class Derive : public Base
{
  public:
    void func(char* name = "derive")
    {
        std::cout << "����������Dervie��func()����" << name << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Derive derive;
    Base* b_ptr = &derive;

    b_ptr->func();  // ��������������麯��������Ĭ�ϵ��β�ֵȴ�ǻ���ģ�ԭ����Ĭ���βε�ֵ���ڱ���ʱ��ȷ���õ�.
    return 0;
}

