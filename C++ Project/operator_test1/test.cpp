// Copyright 2017.���|�|
// author�����|�|
// ���������
#include <iostream>
using std::cout;
using std::endl;

#include "base.h"

int main(int argc, char* argv[])
{
    Base b;
    
    b->func();  // �����������ã��൱��b.operator ->()->func()
    return 0;
}
