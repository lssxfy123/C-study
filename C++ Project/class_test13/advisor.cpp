#include "advisor.h"

#include <iostream>

Advisor::Advisor()
{
	number_of_meeting_ = 0;
	std::cout << "Default Advisor()" << std::endl;
}

Advisor::Advisor(int number)
{
    number_of_meeting_ = number;
    std::cout << "Advisor()" << std::endl;
}
