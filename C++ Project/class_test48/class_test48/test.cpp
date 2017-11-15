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

    // ��Java�У�A��B�е�func�����ṹ������
    // ����C++�У�����ֻ�ܷ�����һ������
    b.func(4);  // B::func()
    b.func(4.5);  // B::func()
    return 0;
}
