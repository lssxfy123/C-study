// 函数的重载与默认参数的函数
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
    std::cout << a << std::endl;
}


void func(float b)
{
    std::cout << b << std::endl;
}
