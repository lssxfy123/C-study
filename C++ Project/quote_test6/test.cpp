// Copyright 2017.刘珅珅
// author：刘珅珅
// 返回非引用和返回引用
#include <iostream>

int n = 8;

int& func1();
int& func2();

int main(int argc, char* argv[])
{
    int& a = func1();
    int& b = func2();

    std::cout << a << std::endl;  // 输出a时，为随机乱数，引用a绑定的临时对象消失了

    int c = func1();
    std::cout << c << std::endl;  // 输出c = 5

    func2() = 9;  // 返回类型为引用时，函数可以作为左值

    std::cout << n << std::endl;  // n为9
    return 0;
}

int& func1()
{
    int a = 5;
    return a;  // 不建议如此返回局部对象给引用
}

int& func2()
{
    return n;
}
