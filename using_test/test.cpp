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

	// func�Ǻ�������,��������print��һ������ָ��
	func* my_func = print;
	my_func();
	return 0;
}