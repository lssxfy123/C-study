#include "sgcc.h"

#include <iostream>

// �����������ռ��ڲ�
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

// Ҳ�����������������������ռ䣬�����������ռ��ⲿ

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

