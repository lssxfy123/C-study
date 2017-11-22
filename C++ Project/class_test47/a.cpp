#include "a.h"

#include <iostream>
using std::cout;
using std::endl;

void A::func(B b)  // 静态函数可以访问其他类的非静态成员
{
    cout << "num  = "<< b.num_ << endl;
}
