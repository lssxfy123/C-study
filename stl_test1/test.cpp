// Copyright 2017.刘珅珅
// author：刘珅珅
// 模板构造函数
#include <iostream>
using namespace std;

template <class T>
class MyClass {
public:
    // 构造函数
    MyClass()
    {
        cout << "调用默认构造函数" << endl;
    }

    // 拷贝构造函数
    MyClass(const MyClass<T>& x)
    {
        cout << "调用拷贝构造函数" << endl;
    }

    // 不同类型的拷贝构造函数
    template <class U> MyClass(const MyClass<U>& x)
    {
        cout << "调用不同参数类型的拷贝构造函数" << endl;
    }
};

int main(int argc, char* argv[])
{
    MyClass<double> d1;
    MyClass<double> d2(d1);
    MyClass<int> i3(d1);
    return 0;
}
