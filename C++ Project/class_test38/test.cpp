// Copyright 2017.���|�|
// author�����|�|
// �����ռ�
#include <iostream>
using std::cout;
using std::endl;

namespace sgcc
{
    class A
    {
      public:
        A()
        {

        }

    };

    void f(const A& a)  // ����A��ͬһ�������ռ�
    {

    }
}

int main(int argc, char* argv[])
{
    sgcc::A a;
    f(a);  // ok��������ʾʹ��sgcc::f
    return 0;
}
