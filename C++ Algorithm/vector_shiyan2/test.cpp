  // Copyright 2017.刘珅珅
  // author：刘珅珅
 // 顺序容器插入元素和迭代器
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
		ilist.push_back(i); // 在ilist链表尾添加元素
	}

	ilist.push_front(10);  // 在ilist链表头添加元素，push_front()只适用于list和deque

	list<int> :: iterator iter;

	iter = ilist.begin();
	++iter; // 迭代器指向链表的第二个元素

	// 在迭代器iter所指向的元素前面插入3个值为11的元素
	ilist.insert(iter, 3, 11);

	for (iter = ilist.begin(); iter != ilist.end(); ++iter)  // 
	{
		cout << *iter << endl;
	}

	int n = ilist.size(); // 返回容器中的元素个数

	cout << "容器的大小为：" << n << endl;

	bool status = ilist.empty(); // 判断容器大小是否为0，是返回true，否则返回false

	if (status)
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
	}

	ilist.resize(12,123); // 调整容器的大小，使其大小为15，新添加的元素值都为123，如果原来容器大小大于15，则删除容器尾部多出来的

	for (iter = ilist.begin(); iter != ilist.end(); ++iter) // 注意要保持迭代器的有效性
	{
		cout << *iter << endl;
	}


	return 0;
}