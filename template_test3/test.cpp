// Copyright 2017.刘珅珅
// author：刘珅珅
// 模板中调用非模板函数
#include <iostream>
using namespace std;

int hash1(int key)
{
	return key % 12;
}

int hash1(const string& key)
{
	int hash_value = 0;
	for (int i = 0; i < key.length(); ++i)
	{
		hash_value = 37 * hash_value + key[i];
	}

	return hash_value;
}

//定义一个函数模板
template <typename T>
void compare(const T &a)
{
	int k = hash1(a);
}

int main(int argc, char* argv[])
{
	compare(5);
	return 0;
}
