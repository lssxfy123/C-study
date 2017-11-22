// Copyright 2017.刘珅珅
// author：刘珅珅
// 类的多态性
#include <iostream>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;

void func(const Shape& sp);  //在func函数中不允许对Shape类的引用sp作修改

void func2(Shape& sp);

void func1(const Rectangle* rect);

int main(int argc,char* argv[])
{
    Circle circle(2.0,5.0,4.0);

    // 调用func()函数时，实际是将基类的引用绑定到了派生类对象上，会触发动态绑定
    // 注意：如果func()的形参不是引用，而直接定义成func(const Shape sp)，则不会
    // 触发动态绑定技术，虚函数不会有效，全部调用基类Shape的area()函数
    func(circle);
    func2(circle);

    Rectangle rect(2.0, 4.0, 1.0, 2.0);
    func(rect);


    Shape shape(5.0, 6.0);

    func1((Rectangle*)&shape);
    return 0;
}

void func(const Shape& sp)
{
    cout << sp.area() << endl;
}

void func1(const Rectangle* rect)
{
    cout << rect->area() << endl;
}

void func2(Shape& sp)
{
    sp.f();
}
