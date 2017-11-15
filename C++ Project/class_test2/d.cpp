#include "d.h"

#include <iostream>

D& D::Display()
{
    std::cout << "Display" << std::endl;
    return *this;
}

const D& D::Display() const
{
    std::cout << "const Display" << std::endl;
    return *this;
}

void D::func()
{

}
