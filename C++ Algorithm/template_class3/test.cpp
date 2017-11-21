// Copyright 2017.刘珅珅
// author：刘珅珅
// 类模板中的友元的测试
#include "bar.cpp"  // 这里要包含.cpp文件，这是由于编译模板时，需要定义模板的源代码
#include <iostream>
using namespace std;

// 友元函数func()不能定义在bar.h或bar.cpp中，否则会引起重复包含
void func()
{
	Bar <int> bar;  //类的友元函数访问类的private和protected成员时，需要使用类对象进行访问
	bar.num = 0;

	bar.fcn();
	
	cout << "友元函数" << bar.num << endl;
}

int main(int argc, char *argv[])
{
	Bar <int> bar;
	func();

	return 0;
}