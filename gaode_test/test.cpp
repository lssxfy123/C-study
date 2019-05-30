// Copyright 2019.刘珅珅
// author：刘珅珅
// C++四种强制类型转换
// static_cast
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
	int i = 10;
	double d1 = i;  // 隐式类型转换b
	double d2 = static_cast<double>(i);
	double d3 = 4.5;
	double* pd = &d3;
	void* d = static_cast<void*>(pd);  // 指针转换为void指针
	double* pd1 = static_cast<double*>(d);  // void指针转换为其它指针
	cout << *pd1 << endl;
	int a = 10;
	const int b = static_cast<const int>(a);

	const int c = 5;
	// int d = static_cast<int>(c);  // error，static_cast不能转换掉const
	// int* p = static_cast<int*>(a);  // error，类型转换无效，不能从int转换为int*
	//void p;  // error，不允许不完整类型
	// void* p = static_cast<int*>(a);  // error，类型转换无效
	void* p = static_cast<int*>(&a);

	Base bb;
	Derived dd;
	Base& bb1 = static_cast<Base&>(dd);  // 上行，安全
	Base* pb = static_cast<Base*>(&dd);  // 上行，安全
	pb->func();  // Print Derived

	Derived& dd1 = static_cast<Derived&>(bb);  // 下行，不安全
	Derived* pdd = static_cast<Derived*>(&bb);  // 下行，不安全
	pdd->func();  // 在VS上为Print Base，但其它编译器不一定
	
	return 0;
}
