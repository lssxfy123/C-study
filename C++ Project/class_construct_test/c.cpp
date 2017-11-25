#include "c.h"

#include <iostream>

C::C():num(15), age(num + 1)
{
    std::cout << "调用A构造函数" << std::endl;
    std::cout << num << std::endl;
    std::cout << age << std::endl;
}

C::~C()
{

}
