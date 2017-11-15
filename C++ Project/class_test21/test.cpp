// 类继承中的函数覆盖和隐藏

#include <iostream>

class Base
{
  public:
    virtual void xfn(int i)
    {
        std::cout << "Base::xfn(int i)" << std::endl;
    }

    void yfn(float f)
    {
        std::cout << "Base::yfn(float f)" << std::endl;
    }

    void zfn()
    {
        std::cout << "Base::zfn()" << std::endl;
    }

    virtual void tfn(int i)
    {
        std::cout << "Base::tfn(int i)" << std::endl;
    }
};

class Derive : public Base
{
  public:
    virtual void xfn(int i)  // 虚函数，函数覆盖
    {
        std::cout << "Derive::xfn(int i)" << std::endl;
    }

    void yfn(int c)  // 隐藏屏蔽基类Base的函数
    {
        std::cout << "Derive::yfn(int c)" << std::endl;
    }

    void zfn()  // 隐藏屏蔽基类Base的函数
    {
        std::cout << "Derive::zfn()" << std::endl;
    }

    virtual void tfn()  // 隐藏屏蔽基类的Base函数，虽然定义为虚函数，但形成不同，不触发动态绑定
    {
        std::cout << "Derive::tfn()" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Derive d;

    Base* b_ptr = &d;
    Derive* d_ptr = &d;

    b_ptr->xfn(5);  // 调用Derive类的xfn()函数
    d_ptr->xfn(5);  // 调用Derive类的xfn()函数

    b_ptr->yfn(3.5);  // 调用Base类的yfn()函数
    d_ptr->yfn(4);  // 调用Derive类的yfn()函数

    b_ptr->zfn();  // 调用Base类的zfn()函数
    d_ptr->zfn();  // 调用Derive类的zfn()函数

    b_ptr->tfn(5);  // 调用Base类的tfn()函数
    // d_ptr->tfn(8);  // error，派生类型的对象无法直接调用基类中的同名函数
    d_ptr->Base::tfn(8);  // ok，可以通过作用域操作符调用基类中的同名函数
    d_ptr->tfn();

    return 0;
}
