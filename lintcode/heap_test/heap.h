#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>

class Heap
{
public:
	Heap();
	Heap(const std::vector<int>& array);

	void Insert(const int& value);
	void Pop();
	const int& FindMin() const;

	void Print() const
	{
		for (int i = 0; i < array_.size(); ++i)
		{
			std::cout << array_[i] << ",";
		}
		std::cout << std::endl;
	}

private:
	void Heapify();
	void SiftDown(int index);
	void SiftUp(int index);

private:
	std::vector<int> array_;
};

#endif
