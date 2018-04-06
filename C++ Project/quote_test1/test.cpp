// Copyright 2017.刘珅珅
// author：刘珅珅
// 引用
#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int& a_reference = a;  // 引用必须初始化
    // 引用一旦初始化，只要该引用存在，就保持绑定到初始化时指定的对象
    // 引用是对象的另一个名字，作用在引用上的所有操作都是作用在该引用
    // 绑定的对象上

    int& b_reference = a_reference;
    std::cout << a << std::endl;  // 0
    std::cout << a_reference << std::endl;  // 0
    std::cout << b_reference << std::endl;

    a = 5;
    std::cout << a << std::endl;  // 5
    std::cout << a_reference << std::endl;  // 5
    std::cout << b_reference << std::endl;

    a_reference = 7;
    std::cout << a << std::endl;  // 7
    std::cout << a_reference << std::endl;  // 7
    std::cout << b_reference << std::endl;

    // 以下输出的两个地址完全相同
    std::cout << &a << std::endl;
    std::cout << &a_reference << std::endl;
    std::cout << &b_reference << std::endl;
    return 0;
}

