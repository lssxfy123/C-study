#ifndef SHAPE_H
#define SHAPE_H
class Shape  // 基类
{
  public:
    Shape(double x,double y);
    virtual double area() const;//定义了一个const常量函数
    //const常量成员函数相当于一个“只读”函数，即不对对象作修改

    virtual Shape& f();

protected:
    double xCoord;
    double yCoord;
};

#endif

