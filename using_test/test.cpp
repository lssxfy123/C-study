#include <iostream>
using namespace std;

using String = std::string;

using Func_ptr = void (*)();

typedef void func();

void print()
{
	cout << "Hello Word!" << endl;
}

int main(int argc, char* argv[])
{
	String my_str = "abc";
	cout << my_str.c_str() << endl;
	Func_ptr func_ptr = print;
	func_ptr();

	// func是函数类型,而函数名print是一个函数指针
	func* my_func = print;
	my_func();
	return 0;
}