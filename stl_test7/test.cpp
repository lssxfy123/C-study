// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11引用叠加规则
#include <iostream>
using namespace std;

void Test(int&& v)
{
}

template<typename T>
void Func(T&& formal_param)
{
    
}

int main(int argc, char* argv[])
{
    int a = 1;
    int&& r = 3;
    //Test(a);  // error，右值引用无法绑定到左值
    //Test(r);  // error，右值引用无法绑定到左值

    // ok，函数模板的形参，右值引用可以绑定到左值
    Func(a);  
    return 0;
}
