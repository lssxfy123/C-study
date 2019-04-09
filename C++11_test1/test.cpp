// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11的新内置类型
#include <iostream>
using namespace std;

void func()
{
	int k = 3;
	constexpr int* p = &k;
}

int main(int argc, char* argv[])
{
    // 新的内置类型long long
    cout << "int size " << sizeof(int) << endl;
    cout << "long size " << sizeof(long) << endl;
    cout << "long long size " << sizeof(long long) << endl;

    // 列表初始化
    int unit_sold = 0;
    int unit_sold1{0};  // 列表初始化

    long double ld = 3.1415926536;
    //int a{ld};  // error，列表初始化不允许收缩转换

    int b = 9;
    // long double ld1{ b };  // error，列表初始化不允许收缩转换

    // constexpr编译时验证是否为常量表达式
    constexpr int mf = 20;
    //mf = 4;  // error，mf为整型常量
    int k = 1;
    //constexpr int limit = k + 1;  // error，k+1不为常量表达式
    constexpr double df = 5.5;

    // p为常量指针
    constexpr int* p = &k;
    k = 2;
    cout << *p << endl;  // 2
    // p = nullptr;  // error，不能改变p的指向
	*p = 3;  // 可以通过*修改指向对象的值
	cout << k << endl;  // 3

	int k1 = 2;
	// 下面是指向常量的指针
	const int* p2 = &k1;
	// *p2 = 5;  // error，不能通过*修改指针指向的对象
	p2 = nullptr;  // 可以习惯指针本身
	
	func();

    // decltype类型指示符
    const int ci = 0;
    decltype(ci) x = 0;  // x为const int
    //x = 5;  // error，x不能修改
    const int& cj = ci;
    decltype(cj) y = x;  // y为const int&

    int i = 42;
    int* p1 = &i;
    int& r = i;
    decltype(r + 0) b1;  // ok，decltype(r)为引用，但r+0不是引用
    //decltype(*p) c1;  // error，*p为解引用操作，decltype将得到引用

    //decltype((i))d;  // error，decltype的变量加上1层或多层括号，得到的是引用
    return 0;
}
