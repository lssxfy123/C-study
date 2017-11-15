// this指针

#include <iostream>

#include "b.h"
#include "c.h"
#include "d.h"

int main(int argc, char* argv[])
{
    B b;
    b.SetHeight(30).SetWidth(40);

    C c1;
    c1.SetHeight(100);
    c1.GetHeight();  // ok，非const对象可以调用const成员函数
    c1.PrintValue();

    const C c2;
    // c2.SetHeight(300);  // error，const对象只能调用const成员函数
    c2.GetHeight();  // ok，可以调用const成员函数

    D d;
    d.Display().func();  // this指针是一个指针常量，本身不能修改，只能指向对象本身

    const D d1;
    d1.Display();
    // d1.Display().func();  // error，返回的this指针是一个指向const对象的const指针，不能调用非const成员函数

    return 0;
}
