  // Copyright 2017.���|�|
  // author�����|�|
  // vector��list������Ԫ�ط���
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	list<int> ilist;

	for (list<int> :: size_type i = 0; i != 10; ++i)
	{
		ilist.push_back(i);
	}



	if (!ilist.empty())
	{
		list<int> :: reference val1 = ilist.back(); // ����ilist�����һ��Ԫ�ص�����
		list<int> :: reference val2 = ilist.front();
	}

	// cout << val1 << endl; // error:��������ʹ������Ԫ�ص�����

	vector<int> ivec;
	ivec[0]; // �����±�Ϊ0��Ԫ�ص����ã�ֻ������vector��deque
	ivec.at(0); // �����±�Ϊ0��Ԫ�ص����ã�ֻ������vector��deque

	list<int> :: iterator iter;
	iter = ilist.begin();
	++iter;

    // ɾ��������iterָ���Ԫ�أ�����һ��ָ��ɾ��Ԫ�غ����Ԫ�صĵ�������
	// ���iterָ�����һ��Ԫ�أ��򷵻صĵ�����ָ�򳬳�ĩ�˵���һ��λ��
	ilist.erase(iter);

	ilist.pop_back(); // ɾ��ilist�����һ��Ԫ��
	ilist.pop_front(); // ɾ��ilist�ĵ�һ��Ԫ��
	
	ilist.clear(); // ���ilist�е�����Ԫ��


	return 0;
}