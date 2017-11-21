  // Copyright 2017.刘珅珅
  // author：刘珅珅
  // vector和list容器的元素访问
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
		list<int> :: reference val1 = ilist.back(); // 返回ilist中最后一个元素的引用
		list<int> :: reference val2 = ilist.front();
	}

	// cout << val1 << endl; // error:不能这样使用容器元素的引用

	vector<int> ivec;
	ivec[0]; // 返回下标为0的元素的引用，只适用于vector和deque
	ivec.at(0); // 返回下标为0的元素的引用，只适用于vector和deque

	list<int> :: iterator iter;
	iter = ilist.begin();
	++iter;

    // 删除迭代器iter指向的元素，返回一个指向被删除元素后面的元素的迭代器。
	// 如果iter指向最后一个元素，则返回的迭代器指向超出末端的下一个位置
	ilist.erase(iter);

	ilist.pop_back(); // 删除ilist的最后一个元素
	ilist.pop_front(); // 删除ilist的第一个元素
	
	ilist.clear(); // 清空ilist中的所有元素


	return 0;
}