// 类的构造函数

#include <iostream>

#include "a.h"
#include "b.h"
#include "c.h"

int main(int argc, char* argv[])
{
    int i = 5;
    int& ref = i;
    B b(ref);
    b.PrintValue();

    C c;
    return 0;
}
