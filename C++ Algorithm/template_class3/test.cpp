// Copyright 2017.���|�|
// author�����|�|
// ��ģ���е���Ԫ�Ĳ���
#include "bar.cpp"  // ����Ҫ����.cpp�ļ����������ڱ���ģ��ʱ����Ҫ����ģ���Դ����
#include <iostream>
using namespace std;

// ��Ԫ����func()���ܶ�����bar.h��bar.cpp�У�����������ظ�����
void func()
{
	Bar <int> bar;  //�����Ԫ�����������private��protected��Աʱ����Ҫʹ���������з���
	bar.num = 0;

	bar.fcn();
	
	cout << "��Ԫ����" << bar.num << endl;
}

int main(int argc, char *argv[])
{
	Bar <int> bar;
	func();

	return 0;
}