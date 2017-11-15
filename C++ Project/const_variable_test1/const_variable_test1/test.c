#include <stdio.h>

#include "a.h"

int main(int argc, char* argv[])
{
    const int a = 5;
    // char buffer[a];  // error，在C语言中const变量不是常量，而是一个不能修改的变量
    return 0;
}

