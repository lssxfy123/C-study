// Copyright 2017.���|�|
// author�����|�|
// ģ���е��÷�ģ�庯��
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

//����һ������ģ��
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
