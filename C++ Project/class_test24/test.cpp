// 虚析构函数

#include <iostream>

class Base
{
  public:
    Base()
    {
        std::cout << "执行Base的构造函数" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "执行Base的析构函数" << std::endl;
    }
};

class Derive : public Base
{
  public:
    Derive()
    {
        std::cout << "执行Derive的构造函数" << std::endl;
    }

    ~Derive()
    {
        std::cout << "执行Derive的析构函数" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Base* b_ptr = new Derive();

    delete b_ptr;  // 动态创建的类对象，必须使用delete删除，否则不会调用析构函数
    b_ptr = NULL;

    return 0;
}

