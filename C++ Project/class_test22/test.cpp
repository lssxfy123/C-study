// 类继承中的函数重载

#include <iostream>

class Base
{
  public:
    virtual void fcn()
    {
        std::cout << "Base::fcn()" << std::endl;
    }
};

class Derive1 : public Base
{
  public:
    void fcn(int i)  // 隐藏屏蔽了基类的fcn()函数，不触发动态绑定
    {
        std::cout << "Derive1::fcn(int i)" << std::endl;
    }
};

class Derive2 : public Derive1
{
  public:
    void fcn()
    {
        std::cout << "Derive2::fcn()" << std::endl;
    }

    void fcn(int i)  // 虚函数也可以被重载
    {
        std::cout << "Derive2::fcn(int i)" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Base b;
    Derive1 d1;
    Derive2 d2;

    Base* b_ptr = &b;
    Base* b1_ptr = &d1;
    Base* b2_ptr = &d2;

    b_ptr->fcn();  // Base::fcn()

    // 尽管b1_ptr和b2_ptr指向的分别是Derive1对象和Derive2对象
    // 但由于它们本身是Base*类型的变量，所以不能调用Derive1和
    // Derive2的自有成员函数
    b1_ptr->fcn();  // Base::fcn()
    b2_ptr->fcn();  // Derive2::fcn()

    return 0;
}
