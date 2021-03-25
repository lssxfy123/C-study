// Copyright(C) 2021 刘珅珅
// Environment: C++
// Date : 2021.3.25
// Insert Delete GetRandom O(1) - 允许重复: lintcode 954

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		srand(time(nullptr));
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		// write your code here
		bool flag = value_indexs_.find(val) != value_indexs_.end();
		numbers_.push_back(val);
		value_indexs_[val].insert(numbers_.size() - 1);
		return flag;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		// write your code here
		if (value_indexs_.find(val) == value_indexs_.end())
		{
			return false;
		}

		int last = numbers_.back();
		int last_index = numbers_.size() - 1;
		// 任意选一个val对应的索引
		int idx = *(value_indexs_[val].begin());
		if (last_index != idx)
		{
			value_indexs_[last].erase(last_index);
		}
		value_indexs_[last].insert(idx);
		numbers_[idx] = last;
		value_indexs_[val].erase(idx);
		numbers_.pop_back();
		if (value_indexs_[val].empty())
		{
			value_indexs_.erase(val);
		}
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		// write your code here
		if (numbers_.size() == 0)
		{
			return -1;
		}
		return numbers_[rand() % numbers_.size()];
	}

private:
	vector<int> numbers_;
	unordered_map<int, unordered_set<int>> value_indexs_;
};

int main(int argc, char* argv[])
{
	unordered_set<int> set;
	set.insert(1);
	set.insert(1);
	return 0;
}
