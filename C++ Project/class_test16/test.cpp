// Copyright 2017.���|�|
// author�����|�|
// �����麯������
#include <iostream>

class Base
{
  public:
    virtual void func()
    {
        number = 5;
        std::cout << "number = " << number << std::endl;
    }

  private:
    int number;
};

class Derive : public Base
{
  public:
    void func()
    {
        Base::func();
        count = 10;
        std::cout << "count = " << count << std::endl;
    }

  private:
    int count;
};

int main(int argc, char* argv[])
{
    Derive derive;
    Base* b_ptr = &derive;

    // b_ptr->Base::func();  // ���û���Base��func()������ͨ�������������::�������麯������
    b_ptr->func();
    return 0;
}
