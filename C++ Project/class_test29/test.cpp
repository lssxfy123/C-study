// 纯虚析构函数

#include <iostream>

class Base
{
  public:
    Base(int i)
    {
        std::cout << "Base()" << std::endl;
    }

    virtual ~Base() = 0;  // 纯虚析构函数，必须进行实现
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
    // Base b(5);  // error，Base为抽象类
    Derive d;
    return 0;
}
