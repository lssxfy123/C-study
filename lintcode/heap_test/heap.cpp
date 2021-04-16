#include "heap.h"

Heap::Heap()
{

}

Heap::Heap(const std::vector<int>& array)
{
	this->array_.assign(array.begin(), array.end());
	Heapify();
}

void Heap::Insert(const int& value)
{
	array_.push_back(value);
	SiftUp(array_.size() - 1);
}

// 删除堆顶元素
void Heap::Pop()
{
	if (array_.size() == 0)
	{
		return;
	}

	array_[0] = array_[array_.size() - 1];
	array_.pop_back();
	SiftDown(0);
}

const int& Heap::FindMin() const {
	return array_[0];
}

// 堆化：自底向上建堆
void Heap::Heapify()
{
	if (array_.size() == 0)
	{
		return;
	}

	for (int i = array_.size() / 2; i >= 0; --i)
	{
		SiftDown(i);
	}
}

// 下滤
void Heap::SiftDown(int index)
{
	int length = array_.size();
	while (index < length)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int min_index = index;

		// 建小根堆
		if (left < length && array_[left] < array_[min_index])
		{
			min_index = left;
		}

		if (right < length && array_[right] < array_[min_index])
		{
			min_index = right;
		}

		// 满足小根堆条件，直接退出
		if (min_index == index)
		{
			break;
		}

		// 交换index和min_index的值
		std::swap(array_[index], array_[min_index]);
		index = min_index;
	}
}

// 上滤
void Heap::SiftUp(int index)
{
	while (index > 0)
	{
		int father_index = (index - 1) / 2;
		// 满足小根堆的特性
		if (array_[father_index] < array_[index])
		{
			break;
		}
		std::swap(array_[father_index], array_[index]);
		index = father_index;
	}
}
