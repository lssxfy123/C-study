#include "base.h"

#include <iostream>
using std::cout;
using std::endl;

Base* Base::operator ->()
{
    cout << "Base ���ص�->�����" << endl;
    return this;
}

void Base::func()
{
    cout << "func()" << endl;
}
