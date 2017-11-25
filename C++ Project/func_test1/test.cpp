// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// º¯ÊıµÄÖØÔØ
#include <iostream>

void func(int a);
void func(float b);

int main(int argc, char* argv[])
{
    int a = 5;
    float f = 3.5;

    func(a);
    func(f);
    return 0;
}

void func(int a)
{
    std::cout << "int " << a << std::endl;
}


void func(float b)
{
    std::cout << "float " << b << std::endl;
}
