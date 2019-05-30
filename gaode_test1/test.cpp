// Copyright 2019.���|�|
// author�����|�|
// C++����ǿ������ת��
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
	// double b = dynamic_cast<double>(a);  // error��dynamic_castֻ������ת��ָ�������
	// double* pd = dynamic_cast<double*>(&a);  // error��dynamic_castֻ���������������ͻ�void��ָ�������
	Base b;
	Derived d;
	Base& bb = dynamic_cast<Base&>(d);  // ���У���ȫ��static_cast��ͬ
	Base* pb = dynamic_cast<Base*>(&d);  // ���У���static_cast��ͬ
	pb->func();  // Print Derived
	Derived* pd = dynamic_cast<Derived*>(&b);  // ���У�pdΪnullptr
	Derived& d1 = dynamic_cast<Derived&>(b);  // ���У����׳��쳣
	return 0;
}
