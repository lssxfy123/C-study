#include <iostream>
using std::cout;
using std::endl;

class A
{
  public:
    void func(int i)
    {
        cout << "A::func()" << endl;
    }
};

class B : public A
{
  public:
    void func(double f)
    {
        cout << "B::func()" << endl;
    }
};

int main(int argc, char* argv[])
{
    B b;

    // 在Java中，A和B中的func函数会构成重载
    // 但在C++中，重载只能发生在一个类中
    b.func(4);  // B::func()
    b.func(4.5);  // B::func()
    return 0;
}
