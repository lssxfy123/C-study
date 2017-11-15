#include "rectangle.h"

#include <iostream>
#include <math.h>
using namespace std;

Rectangle::Rectangle(double x, double y, double x1, double y1) : Shape(x,y)
{
    x2Coord = x1;
    y2Coord = y1;
}

double Rectangle::area() const
{
    cout << "����Rectangle���area����" << endl;
    return fabs((xCoord - x2Coord ) * (yCoord - y2Coord));
}

