#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Hash(int key)
{
    return key % 10;
}

// 解决冲突的函数
// 线性探测f(i) = i
int ResolveCollision(int i)
{
    return i;
}

// 距离n最近的素数
int NextPrime(int n)
{
    if (n % 2 == 0)
    {
        ++n;
    }

    bool isPrime = true;
    for (; ; n += 2)
    {
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            return n;
        }
        isPrime = true;
    }
    return n;
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

    // 成功平均查找长度
    void CalculateSuccessAverageSearchLength()
    {
        double success_average_search_length = 0;
        for (int i = 0; i < current_size_; ++i)
        {
            HashEntry& entry = array_[i];
            if (Contains(entry.element))
            {
                success_average_search_length += (entry.collision_count + 1);
            }
            //if (entry.collision_count > 0)
                
        }
        success_average_search_length /= current_size_;
        cout << "成功平均查找长度为：" << success_average_search_length << endl;
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
        if (current_size_ >= array_.size())
        {
            Rehash();
        }
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
            array_[i].collision_count = 0;
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

    void Rehash()
    {
        vector<HashEntry> old_array = array_;
        array_.resize(NextPrime(2 * array_.size()));
        for (int i = 0; i < array_.size(); ++i)
        {
            array_[i].info = EMPTY;
        }

        current_size_ = 0;
        for (int i = 0; i < old_array.size(); ++i)
        {
            if (old_array[i].info == ACTIVE)
            {
                Insert(old_array[i].element);
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
        int hase_value = Hash(x);
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
        int collision_count;
        HashEntry(const HashObj& e = HashObj(), EntryType type = EMPTY)
            : element(e), info(type), collision_count(0)
        {}
    };

private:
    vector<HashEntry> array_;
    int current_size_;
};

#endif  // HASH_TABLE_H
