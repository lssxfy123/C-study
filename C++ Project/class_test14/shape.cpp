#include "shape.h"
#include <iostream>
using namespace std;


Shape::Shape(double x,double y):xCoord(x), yCoord(y)
{
}

double Shape::area() const //const������Ա�������ں���ԭ�������ͺ������崦�������const�޶�
{
    cout << "����Shape���area����" << endl;
    return 0.0;
}

Shape& Shape::f()
{
    cout << "����Shape���f()����" << endl;
    xCoord = 0;
    return *this;
}
