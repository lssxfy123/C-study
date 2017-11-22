// Copyright 2017.刘珅珅
// author：刘珅珅
// 命名空间
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

    void f(const A& a)  // 与类A在同一个命名空间
    {

    }
}

int main(int argc, char* argv[])
{
    sgcc::A a;
    f(a);  // ok，不用显示使用sgcc::f
    return 0;
}
