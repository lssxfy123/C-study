// Copyright 2017.刘珅珅
// author：刘珅珅
// 类中成员的初始化
#include <iostream>
using namespace std;

class A {
public:
	A();
	A(const A& a);
	A(string name);
	~A();

public:
	A& operator=(const A& org);
};

A::A()
{
	cout << "construct null" << endl;
}

A::A(string name)
{
	cout << "construct with name" << endl;
}

A::A(const A& a)
{
	cout << "copy construct " << endl;
}

A::~A()
{
	cout << "destructor" << endl;
}

A& A::operator=(const A& org)
{
	cout << "operator =" << endl;
	return *this;
}

A a;

int main()
{
	a = A("teatcher");  // 执行构造函数A(string)后会立即执行析构函数
	int b = 0;

	A a1;
	a1 = A("student");  // 执行构造函数A(string)后会立即执行析构函数
	int c = 0;

	return 0;
}
