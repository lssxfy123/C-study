// Copyright(C) 2021 Áõ«|«|
// Environment: C++
// Date : 2021.4.16
// ¶ÑµÄÊµÏÖ
#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	vector<int> array{ 3, 2, 1, 4, 5 };
	Heap heap(array);
	heap.Pop();
	heap.Print();
	Heap heap1;
	heap1.Insert(3);
	heap1.Insert(2);
	heap1.Insert(1);
	heap1.Insert(4);
	heap1.Insert(5);
	heap1.Print();
	return 0;
}