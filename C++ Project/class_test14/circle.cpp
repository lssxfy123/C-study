#include "circle.h"

#include <iostream>
using namespace std;


Circle::Circle(double x,double y,double r)
:Shape(x,y)  //注意：Shape类没有默认的构造函数，所有需要用冒号表达式来调用其构造函数
{
    radius = r;
}

double Circle::area() const
{
    cout << "调用Circle类的area函数" << endl;
    return 3.14 * radius * radius;
}

Circle& Circle::f()
{
    cout << "调用Circle类的f()函数" << endl;
    radius = 2.0;
    return *this;
}

