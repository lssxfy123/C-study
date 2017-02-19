#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// MPQ中的hash算法
// 密码表
unsigned long CrytographTable[1280];

// 解决冲突的函数
// 线性探测f(i) = i
int ResolveCollision(int i)
{
    return i;
}

// 生成长度为1280的密码表
void CreateCryTable()
{
    unsigned long seed = 0x00100001;
    for (unsigned long i = 0; i < 0x100; i++)
    { 
        for (unsigned long j = i, k = 0; k < 5; k++, j += 0x100)
        { 
            unsigned long first, second;
            seed = (seed * 125 + 3) % 0x2AAAAB;
            first = (seed & 0xFFFF) << 0x10; 
            seed = (seed * 125 + 3) % 0x2AAAAB;
            second = (seed & 0xFFFF); 
            CrytographTable[j] = ( first | second );
        } 
    }
}

// Blizzard:One-way hash
int hash(const string& key, unsigned long hash_type)
{
    unsigned long seed_first = 0x7FED7FED;
    unsigned long seed_second = 0xEEEEEEEE;
    int ch;
    for (int i = 0; i < key.length(); ++i)
    {
        ch = toupper(key[i]);
        seed_first = CrytographTable[(hash_type << 8) + ch] ^ (seed_first + seed_second);
        seed_second = ch + seed_first + seed_second + (seed_second << 5) + 3;
    }
    return seed_first;
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


template <typename Key>
class HashTable
{
public:
    explicit HashTable(int size = 23) : current_size_(0)
    {
        hash_list_.resize(size);
        MakeEmpty();
    }

    bool Contains(const Key& x) const
    {
        int current_pos = FindPos(x);
        if (current_pos >= 0)
        {
            return IsActive(current_pos);
        }
        return false;
    }

    bool IsActive(int current_pos) const
    {
        return hash_list_[current_pos].info_ == ACTIVE;
    }

    void MakeEmpty()
    {
        current_size_ = 0;
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            hash_list_[i].info_ = EMPTY;
            hash_list_[i].hash_first_ = -1;
            hash_list_[i].hash_second_ = -1;
            hash_list_[i].count_ = 0;
        }
    }

    bool Insert(const Key& x)
    {
        // 参考hash_test2
        // 利用三个hash值插入，一个hash位置，另外两个验证
        // 如果hash位置为空，则直接插入，如果hash的位置不为空
        // 则使用验证hash校验是否为相同字符串，如果相同，将Value+1
        // 如果不同，则说明发生冲突，利用线性探测解决冲突
        int current_pos = FindPos(x);
        if (current_pos >= 0)
        {
            if (IsActive(current_pos))
            {
                hash_list_[current_pos].count_ += 1;
            }
            else {
                hash_list_[current_pos].key_ = x;
                hash_list_[current_pos].info_ = ACTIVE;
                hash_list_[current_pos].count_ = 1;
                hash_list_[current_pos].hash_first_ = MyHash(x, 1);
                hash_list_[current_pos].hash_second_ = MyHash(x, 2);
            }
            return true;
        } else {
            return false;
        }
    }

    bool Remove(const Key& x)
    {
        int current_pos = FindPos(x);
        if (current_pos > =0)
        {
            if (!IsActive(current_pos))
            {
                return false;
            }
            hash_list_[current_pos].info_ = DELETED;
            return true;
        }
        return false;
    }

    void PrintTable()
    {
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            if (hash_list_[i].info_ == ACTIVE)
            {
                cout << "映射到Hash表第 " << i << "个位置的元素为: " << hash_list_[i].key_ << endl;
                cout << "其个数为: " << hash_list_[i].count_ << endl;
            }
        }
    }

    void GetMaxCountItems()
    {
        // 获取热门查询的前3个
        // 考虑使用优先队列-堆
        int number = 3;
    }

private:
    int FindPos(const Key& x) const
    {
        int current_pos = MyHash(x, 0);
        int hash_first = MyHash(x, 1);
        int hash_second = MyHash(x, 2);
        current_pos = current_pos % hash_list_.size();
        int original_pos = current_pos;
        int collision_count = 1;
        while (hash_list_[current_pos].info_ != EMPTY)
        {
            if (hash_list_[current_pos].hash_first_ == hash_first
                && hash_list_[current_pos].hash_second_ == hash_second)
            {
                return current_pos;
            } else
            {
                current_pos = original_pos + ResolveCollision(collision_count);
                ++collision_count;
                if (current_pos >= hash_list_.size())
                {
                    current_pos -= hash_list_.size();
                }

                // 哈希表没有位置了
                if (current_pos == original_pos)
                {
                    return -1;
                }
            }
        }

        return current_pos;
    }

    // 哈希函数
    int  MyHash(const Key& x, unsigned long hash_type) const
    {
        int hase_value = hash(x, hash_type);
        return hase_value ;
    }

private:
    enum EntryType {ACTIVE, EMPTY, DELETED};
    struct HashObj
    {
        Key key_;
        int count_;
        EntryType info_;
        int hash_first_;  // 校验hash
        int hash_second_;  // 校验hash
        HashObj(const Key& key = Key())
            : key_(key), count_(0)
        {}
    };

private:
    int current_size_;
    vector<HashObj> hash_list_;
};

#endif  // HASH_TABLE_H

