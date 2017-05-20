// Copyright 2017.刘珅珅
// author：刘珅珅
// 构造函数的一致性初始化
#include <iostream>
using namespace std;

class P1
{
public:
    P1(int a, int b)
    {
        cout << "p1 constructor" << endl;
    }
};

class P2
{
public:
    P2(int a, int b)
    {
        cout << "p2 constructor" << endl;
    }

    // 初值列
    P2(initializer_list<int> list)
    {
        cout << "p2 initializer list" << endl;
    }
};

int main(int argc, char* argv[])
{
    P1 p(3, 4);  // ok
    P1 p1{ 4, 5 };  // ok

    // 如果构造函数加上一个explicit关键字
    // 此处会报错，不能进行隐式转换
    P1 p2 = { 5, 6 };  // ok，进行了隐式转换

    P2 p3(1, 2);  // p2 constructor
    P2 p4{ 3, 4 };  // p2 initializer list
    P2 p5{ 5, 6, 7, 8 };  // p2 initializer list
    return 0;
}
