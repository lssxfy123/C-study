#ifndef SHAPE_H
#define SHAPE_H
class Shape  // ����
{
  public:
    Shape(double x,double y);
    virtual double area() const;//������һ��const��������
    //const������Ա�����൱��һ����ֻ���������������Զ������޸�

    virtual Shape& f();

protected:
    double xCoord;
    double yCoord;
};

#endif

