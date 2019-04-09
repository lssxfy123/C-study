// Copyright 2017.���|�|
// author�����|�|
// ���г�Ա�ĳ�ʼ��
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
	a = A("teatcher");  // ִ�й��캯��A(string)�������ִ����������
	int b = 0;

	A a1;
	a1 = A("student");  // ִ�й��캯��A(string)�������ִ����������
	int c = 0;

	return 0;
}
