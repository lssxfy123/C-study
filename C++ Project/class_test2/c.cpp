#include "c.h"

#include <iostream>

C::C():width(10)
{
    // width = 10;  // error��const��Ա���������ڹ��캯���ĳ�ʼ���б��г�ʼ��
}

C::~C()
{

}

int C::GetHeight() const
{
    // height = 100;  //error�� const�������ܸı���ĳ�Ա����
    // PrintValue();  //error��const�������ܵ�����ķ�const��Ա����
    return height;
}

void C::PrintValue()
{
    // GetHeight();  // ok����const��Ա�������Ե���const��Ա����
    std::cout << "height = " << height << " width = " << width << std::endl;
}

C& C::SetHeight(int height)
{
    this->height = height;
    return *this;
}

