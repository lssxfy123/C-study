// Copyright 2017.���|�|
// author�����|�|
// ��̳��й��캯���ĵ���
#include <iostream>

class Base
{
  public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    ~Base()
    {

    }
};

class Derive : public Base
{
  public:
    Derive()
    {
        std::cout << "Derive()" << std::endl;
    }

    ~Derive()
    {

    }
};

int main(int argc, char* argv[])
{
    Base* b_ptr = NULL; // ����ָ�벻����ù��캯��

    b_ptr = new Derive();
    delete b_ptr;
    b_ptr = NULL;

    Derive d;
    Base& b_ref = d;  // �������ò�����ù��캯��

    return 0;
}
