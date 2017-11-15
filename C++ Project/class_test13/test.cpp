#include <iostream>

#include "graduatestudent.h"

int main(int argc, char* argv[])
{
    GraduateStudent gs;

    gs.AddCourse(3, 4.5);
    gs.Display();
    return 0;
}
