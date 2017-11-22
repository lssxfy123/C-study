// Copyright 2017.���|�|
// author�����|�|
// ��Ķ�̬��
#include <iostream>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;

void func(const Shape& sp);  //��func�����в������Shape�������sp���޸�

void func2(Shape& sp);

void func1(const Rectangle* rect);

int main(int argc,char* argv[])
{
    Circle circle(2.0,5.0,4.0);

    // ����func()����ʱ��ʵ���ǽ���������ð󶨵�������������ϣ��ᴥ����̬��
    // ע�⣺���func()���ββ������ã���ֱ�Ӷ����func(const Shape sp)���򲻻�
    // ������̬�󶨼������麯��������Ч��ȫ�����û���Shape��area()����
    func(circle);
    func2(circle);

    Rectangle rect(2.0, 4.0, 1.0, 2.0);
    func(rect);


    Shape shape(5.0, 6.0);

    func1((Rectangle*)&shape);
    return 0;
}

void func(const Shape& sp)
{
    cout << sp.area() << endl;
}

void func1(const Rectangle* rect)
{
    cout << rect->area() << endl;
}

void func2(Shape& sp)
{
    sp.f();
}
