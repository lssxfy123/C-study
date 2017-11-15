// C++虚函数表

#include <iostream>

class Base
{
  public:

    void func()  // 不是虚函数，不会在虚函数表中
    {
        std::cout << "Base::func()" << std::endl;
    }

    virtual void f()
    {
        std::cout << "Base::f()" << std::endl;
    }

    virtual void g()
    {
        std::cout << "Base::g()" << std::endl;
    }

    virtual void h()
    {
        std::cout << "Base::h()" << std::endl;
    }
};

class Derive : public Base
{
  public:
    void f()
    {
        std::cout << "Derive::f()" << std::endl;
    }

    void g()
    {
        std::cout << "Derive::g()" << std::endl;
    }

    void h()
    {
        std::cout << "Derive::h()" << std::endl;
    }

  private:
    virtual void test()  // 自有的虚函数，也会在Derive对象的虚函数表中
    {
        std::cout << "Derive::test()" << std::endl;
    }
};

typedef void (*Fun)(void);

int main(int argc, char* argv[])
{
    Base b;

    Fun Fun_ptr = NULL;

    // 下面两个输出是相同的，都是虚函数表的地址
    // 原因是虚函数表存放在对象的首地址
    std::cout << "虚函数表地址：" << &b << std::endl;

    // 强制转换为整型指针得到的指针指向对象的首地址
    std::cout << (int*)(&b) << std::endl;

    // 把指针的值当作一个整数取出来，也可以把一个整数值当作地址赋给一个指针

    int n = *(int*)(&b);  // 这里得到的是虚函数表，它也是一个指针，也可以看成是一个地址
    std::cout << (int*)n << std::endl;  // 这里得到的是虚函数表的首地址

    // 这里需要将&b强制转换成int*，然后取得其指向的对象，然后在强制转换成int*
    // 这是因为虚函数表中存放的是对象的虚函数的函数指针
    std::cout << "虚函数表-第一个函数地址：" << (int*)*(int*)(&b) << std::endl;

    // (int*)(&b)：虚函数表的存放地址，对象b的首地址
    // (int*)*(int*)(&b)：虚函数表的首地址，第一个虚函数的存放地址
    // (*((int*)*(int*)(&b)))：第一个虚函数
    Fun_ptr = (Fun)(*((int*)*(int*)(&b)));

    Fun_ptr();  // 调用Base::f()

    Fun_ptr = (Fun)*((int*)*(int*)(&b) + 1);
    Fun_ptr();  // 调用Base::g()

    Fun_ptr = (Fun)*((int*)*(int*)(&b) + 2);
    Fun_ptr();  // 调用Base::h()

    Base* b_ptr = new Derive();

    std::cout << "虚函数表地址：" << b_ptr << std::endl;

    std::cout << "虚函数表-第一个函数地址：" << (int*)*(int*)(b_ptr) << std::endl;

    // Fun_ptr = (Fun)*((int*)*(int*)(b_ptr));
    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr));

    Fun_ptr();  // 调用Derive::f()

    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr) + 1);
    Fun_ptr();  // 调用Derive::g()

    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr) + 2);
    Fun_ptr();  // 调用Derive::h()

    // 这是虚函数表造成的问题，我们可以通过这种方式来访问派生类自有的并且是私有的虚函数
    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr) + 3);
    Fun_ptr();  // 调用Derive::test()

    delete b_ptr;
    b_ptr = NULL;

    return 0;
}
