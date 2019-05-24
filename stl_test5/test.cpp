// Copyright 2017.刘珅珅
// author：刘珅珅
// 右值引用
#include <iostream>
using namespace std;

//bool isRValue(int&& r)
//{
//    cout << "右值" << endl;
//    return true;
//}
//
//bool isRValue(int& l)
//{
//    cout << "左值" << endl;
//    return false;
//}

int main(int argc, char* argv[])
{
    int a = 5;
    const int b = 6;
    int c = 7;

    // 非常量右值引用可以绑定到非常量右值
    int&& r1 = 4;  // 非常量右值
    r1 = 5;  // 可以这样写代码，但没有意义
    //int&& r2 = a;  // error，右值引用不能绑定到左值
    int&& r3 = a + c;  // 临时对象，非常量右值

    // 常量右值引用可以绑定到非常量右值和常量右值
    // 常量右值引用本身没有现实意义
    const int&& r4 = 5;
    const int&& r5 = a + b;  // 常量右值
    //const int&& r6 = a;  // error，不能绑定到左值

    // 注意：绑定到右值的右值引用本身是一个左值
    // 因为它有名字
    //int&& r7 = r1;  // error，不能绑定到左值
    int&& r8 = move(r1);  // ok，通过move将左值变成右值
    return 0;
}
