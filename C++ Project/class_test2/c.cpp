#include "c.h"

#include <iostream>

C::C():width(10)
{
    // width = 10;  // error，const成员变量必须在构造函数的初始化列表中初始化
}

C::~C()
{

}

int C::GetHeight() const
{
    // height = 100;  //error： const函数不能改变类的成员变量
    // PrintValue();  //error：const函数不能调用类的非const成员函数
    return height;
}

void C::PrintValue()
{
    // GetHeight();  // ok，非const成员函数可以调用const成员函数
    std::cout << "height = " << height << " width = " << width << std::endl;
}

C& C::SetHeight(int height)
{
    this->height = height;
    return *this;
}

