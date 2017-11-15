#include <iostream>
using std::cout;
using std::endl;

#include "a.h"
#include "b.h"

int main(int argc, char* argv)
{
    B b;
    A::func(b);
    return 0;
}
