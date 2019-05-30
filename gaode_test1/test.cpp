// Copyright 2019.刘珅珅
// author：刘珅珅
// C++四种强制类型转换
// dynamic_cast
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func()
	{
		cout << "Print Base" << endl;
	}
};

class Derived : public Base
{
public:
	void func()
	{
		cout << "Print Derived" << endl;
	}
};

int main(int argc, char* argv[])
{
	int a = 9;
	// double b = dynamic_cast<double>(a);  // error，dynamic_cast只能用于转换指针和引用
	// double* pd = dynamic_cast<double*>(&a);  // error，dynamic_cast只能用于完整类类型或void的指针和引用
	Base b;
	Derived d;
	Base& bb = dynamic_cast<Base&>(d);  // 上行，安全与static_cast相同
	Base* pb = dynamic_cast<Base*>(&d);  // 上行，与static_cast相同
	pb->func();  // Print Derived
	Derived* pd = dynamic_cast<Derived*>(&b);  // 下行，pd为nullptr
	Derived& d1 = dynamic_cast<Derived&>(b);  // 下行，会抛出异常
	return 0;
}
