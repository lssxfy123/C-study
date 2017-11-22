// Copyright 2017.刘珅珅
// author：刘珅珅
// 类的组合
#include <iostream>
#include "graduatestudent.h"

int main(int argc, char* argv[])
{
    GraduateStudent gs;

    gs.AddCourse(3, 4.5);
    gs.Display();
    return 0;
}
