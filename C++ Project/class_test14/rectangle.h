
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"//һ��Ҫ��ӻ����ͷ�ļ�

class Rectangle:public Shape
{
  public:
    Rectangle(double x, double y, double x1, double y1);
    virtual double area() const;

  protected:
    double x2Coord;
    double y2Coord;
};
#endif

