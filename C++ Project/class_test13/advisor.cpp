#include "advisor.h"

#include <iostream>

Advisor::Advisor(int number)
{
    number_of_meeting_ = number;
    std::cout << "Advisor()" << std::endl;
}
