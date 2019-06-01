// Copyright 2019.刘珅珅
// author：刘珅珅
// C++四种强制类型转换
// const_cast
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    const int i = 10;
    // int& r = i;  // error，左值引用无法绑定常量
    int& r = const_cast<int&>(i);  // ok
    r = 100;

    // 通过引用修改了r后，i并未发生变化
    // 这是由于对于const变量，编译器会进行优化，
    // 将其放入寄存器中，每次使用直接从寄存器取值
    // 即使在内存中修改了它的值，编译器也无法知晓
    cout << "r = " << r << endl;  // 100
    cout << "i = " << i << endl;  // 10

    // 使用volatile关键字，保证编译器
    // 每次使用都从内存中取值
    const volatile int j = 10;
    int& r1 = const_cast<int&>(j);
    r1 = 100;
    cout << "r1 = " << r1 << endl;  // 100
    cout << "j = " << j << endl;  // 100
    return 0;
}
