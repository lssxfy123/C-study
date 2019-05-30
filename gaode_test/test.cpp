// Copyright 2019.���|�|
// author�����|�|
// C++����ǿ������ת��
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
	double d1 = i;  // ��ʽ����ת��b
	double d2 = static_cast<double>(i);
	double d3 = 4.5;
	double* pd = &d3;
	void* d = static_cast<void*>(pd);  // ָ��ת��Ϊvoidָ��
	double* pd1 = static_cast<double*>(d);  // voidָ��ת��Ϊ����ָ��
	cout << *pd1 << endl;
	int a = 10;
	const int b = static_cast<const int>(a);

	const int c = 5;
	// int d = static_cast<int>(c);  // error��static_cast����ת����const
	// int* p = static_cast<int*>(a);  // error������ת����Ч�����ܴ�intת��Ϊint*
	//void p;  // error����������������
	// void* p = static_cast<int*>(a);  // error������ת����Ч
	void* p = static_cast<int*>(&a);

	Base bb;
	Derived dd;
	Base& bb1 = static_cast<Base&>(dd);  // ���У���ȫ
	Base* pb = static_cast<Base*>(&dd);  // ���У���ȫ
	pb->func();  // Print Derived

	Derived& dd1 = static_cast<Derived&>(bb);  // ���У�����ȫ
	Derived* pdd = static_cast<Derived*>(&bb);  // ���У�����ȫ
	pdd->func();  // ��VS��ΪPrint Base����������������һ��
	
	return 0;
}
