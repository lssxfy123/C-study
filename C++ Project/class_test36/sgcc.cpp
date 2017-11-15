#include "sgcc.h"

#include <iostream>

// 定义在命名空间内部
namespace sgcc
{
    int n = 0;

    A::A()
    {
        std::cout << "A()" << std::endl;
    }

    A::~A()
    {
        std::cout << "~A()" << std::endl;
    }

    A& A::Set()
    {
        std::cout << "Set()" << std::endl;
        return *this;
    }
}

// 也可以像下面这样定义命名空间，定义在命名空间外部

//int sgcc::n = 0;
//
//sgcc::A::A()
//{
//    std::cout << "A()" << std::endl;
//}
//
//sgcc::A::~A()
//{
//    std::cout << "~A()" << std::endl;
//}
//
//sgcc::A& sgcc::A::Set()
//{
//    std::cout << "Set()" << std::endl;
//    return *this;
//}

