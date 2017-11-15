#include "b.h"

#include <iostream>

// 注意，这里构造函数的形参应定义为引用类型，如果定义为普通类型的i，
// 用其初始化引用ref后，构造函数执行完毕后，i会析构掉，引用ref的值就会是未知的随机数

B::B(int& i):ten(10), ref(i), a(i)
{
    std::cout << "调用B构造函数" << std::endl;
}

B::~B()
{

}

void B::PrintValue()
{
    std::cout << ten << std::endl;
    std::cout << ref << std::endl;
}
