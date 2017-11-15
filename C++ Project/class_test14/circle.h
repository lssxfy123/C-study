#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"//一定要添加基类的头文件

class Circle:public Shape
{
  public:
    Circle(double x,double y,double r);
    virtual double area() const;  // 这里的virtual可以省略，因为基类中已经定义了area()函数为虚函数
    Circle& f();  // 尽管在返回值上与基类Shape中f()的返回值不同，但f()仍然是虚函数

  protected:
    double radius;
};
#endif

