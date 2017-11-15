#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"//һ��Ҫ��ӻ����ͷ�ļ�

class Circle:public Shape
{
  public:
    Circle(double x,double y,double r);
    virtual double area() const;  // �����virtual����ʡ�ԣ���Ϊ�������Ѿ�������area()����Ϊ�麯��
    Circle& f();  // �����ڷ���ֵ�������Shape��f()�ķ���ֵ��ͬ����f()��Ȼ���麯��

  protected:
    double radius;
};
#endif

