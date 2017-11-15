#include "shape.h"
#include <iostream>
using namespace std;


Shape::Shape(double x,double y):xCoord(x), yCoord(y)
{
}

double Shape::area() const //const常量成员函数，在函数原型声明和函数定义处都必须加const限定
{
    cout << "调用Shape类的area函数" << endl;
    return 0.0;
}

Shape& Shape::f()
{
    cout << "调用Shape类的f()函数" << endl;
    xCoord = 0;
    return *this;
}
