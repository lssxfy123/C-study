  // Copyright 2017.���|�|
  // author�����|�|
 // ˳����������Ԫ�غ͵�����
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main(int argc, char *argv[])
{
	list<int> ilist;

	for (list<int> :: size_type i = 0; i != 10; ++i)
	{
		ilist.push_back(i); // ��ilist����β���Ԫ��
	}

	ilist.push_front(10);  // ��ilist����ͷ���Ԫ�أ�push_front()ֻ������list��deque

	list<int> :: iterator iter;

	iter = ilist.begin();
	++iter; // ������ָ������ĵڶ���Ԫ��

	// �ڵ�����iter��ָ���Ԫ��ǰ�����3��ֵΪ11��Ԫ��
	ilist.insert(iter, 3, 11);

	for (iter = ilist.begin(); iter != ilist.end(); ++iter)  // 
	{
		cout << *iter << endl;
	}

	int n = ilist.size(); // ���������е�Ԫ�ظ���

	cout << "�����Ĵ�СΪ��" << n << endl;

	bool status = ilist.empty(); // �ж�������С�Ƿ�Ϊ0���Ƿ���true�����򷵻�false

	if (status)
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ��" << endl;
	}

	ilist.resize(12,123); // ���������Ĵ�С��ʹ���СΪ15������ӵ�Ԫ��ֵ��Ϊ123�����ԭ��������С����15����ɾ������β���������

	for (iter = ilist.begin(); iter != ilist.end(); ++iter) // ע��Ҫ���ֵ���������Ч��
	{
		cout << *iter << endl;
	}


	return 0;
}