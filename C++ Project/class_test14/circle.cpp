#include "circle.h"

#include <iostream>
using namespace std;


Circle::Circle(double x,double y,double r)
:Shape(x,y)  //ע�⣺Shape��û��Ĭ�ϵĹ��캯����������Ҫ��ð�ű��ʽ�������乹�캯��
{
    radius = r;
}

double Circle::area() const
{
    cout << "����Circle���area����" << endl;
    return 3.14 * radius * radius;
}

Circle& Circle::f()
{
    cout << "����Circle���f()����" << endl;
    radius = 2.0;
    return *this;
}

