// ������������

#include <iostream>

class Base
{
  public:
    Base(int i)
    {
        std::cout << "Base()" << std::endl;
    }

    virtual ~Base() = 0;  // ���������������������ʵ��
};

Base::~Base()
{

}

class Derive : public Base
{
  public:
      Derive() : Base(5)
    {

    }

    ~Derive()
    {

    }
};

int main(int argc, char* argv[])
{
    // Base b(5);  // error��BaseΪ������
    Derive d;
    return 0;
}
