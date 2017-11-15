#include "base.h"

#include <iostream>
using std::cout;
using std::endl;

Base* Base::operator ->()
{
    cout << "Base ÖØÔØµÄ->ÔËËã·û" << endl;
    return this;
}

void Base::func()
{
    cout << "func()" << endl;
}
