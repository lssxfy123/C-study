#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hash(int key)
{
    return key % 10;
}

// 解决冲突的函数
// 线性探测f(i) = i * i
int ResolveCollision(int i)
{
    return i * i;
}

template<typename HashObj>
class HashTable
{
public:
    explicit HashTable(int size = 23)
    {
        array_.resize(size);
        MakeEmpty();
    }

    bool Contains(const HashObj& x) const
    {
        return IsActive(FindPos(x));
    }

    bool Insert(const HashObj& x)
    {
        int current_pos = FindPos(x);
        if (IsActive(current_pos))
        {
            return false;
        }

        array_[current_pos] = HashEntry(x, ACTIVE);
        ++current_size_;
        return true;
    }

    bool IsActive(int current_pos) const
    {
        return array_[current_pos].info == ACTIVE;
    }

    void MakeEmpty()
    {
        current_size_ = 0;
        for (int i = 0; i < array_.size(); ++i)
        {
            array_[i].info = EMPTY;
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < array_.size(); ++i)
        {
            if (array_[i].info == ACTIVE)
            {
                cout << "映射到Hash表第 " << i << "个位置的元素为" << array_[i].element << endl;
            }
        }
    }

    bool Remove(const HashObj& x)
    {
        int current_pos = FindPos(x);
        if (!IsActive(current_pos))
        {
            return false;
        }
        array_[current_pos].info = DELETED;
        return true;
    }

public:
    enum EntryType {ACTIVE, EMPTY, DELETED};

private:
    int FindPos(const HashObj& x) const
    {
        int current_pos = MyHash(x);
        int original_pos = current_pos;
        int collision_count = 1;
        while (array_[current_pos].info != EMPTY
            && array_[current_pos].element != x)
        {
            current_pos = original_pos + ResolveCollision(collision_count);
            ++collision_count;
            if (current_pos >= array_.size())
            {
                current_pos -= array_.size();
            }
        }

        return current_pos;
    }

    // 哈希函数
    int MyHash(const HashObj& x) const
    {
        int hase_value = hash(x);
        hase_value %= array_.size();
        if (hase_value < 0)
            hase_value += array_.size();

        return hase_value;
    }

private:
    struct HashEntry
    {
        HashObj element;
        EntryType info;
        HashEntry(const HashObj& e = HashObj(), EntryType type = EMPTY)
            : element(e), info(type)
        {}
    };

private:
    vector<HashEntry> array_;
    int current_size_;
};

#endif  // HASH_TABLE_H
