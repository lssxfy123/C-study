// 类的多态性

#include <iostream>
using namespace std;

class A  // 基类
{
  public:
    virtual A* f()
    {
        cout << "A的f()" << endl;
        return this;
    }
};

class B : public A  // 派生类
{
  public:
    virtual B* f()  // 尽管和基类中的f()的返回值类型不同，但f()仍然是虚函数
    {
        cout << "B的f()" << endl;
        return this;
    }
};

int main(int argc, char* argv[])
{
    A* a_ptr = new A;
    a_ptr->f();  // 执行A的f()
    delete a_ptr;
    a_ptr = NULL;

    a_ptr = new B;  // 基类指针指向派生类对象
    a_ptr->f();  // 执行B的f()

    delete a_ptr;
    a_ptr = NULL;

    B b;
    A& a_ref = b;  // 基类引用绑定派生类对象
    a_ref.f();  // 执行B的f()

    A a = b;
    a.f();  // 执行A的f()，基类的对象直接调用，不触发动态绑定

    B* b_ptr = NULL;
    a_ptr = new A;
    b_ptr = (B*)a_ptr;  // 这样做是不安全的
    b_ptr->f();  // 执行A的f()，b_ptr只能调用基类A的函数

    delete a_ptr;
    a_ptr = NULL;
    b_ptr = NULL;

    return 0;
}
