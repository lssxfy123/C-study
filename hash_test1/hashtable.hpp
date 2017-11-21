#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// C++11中带有自身的hash函数
int Hash(int key)
{
    return key % 12;
}

int Hash(const string& key)
{
    int hash_value = 0;
    for (int i = 0; i < key.length(); ++i)
    {
        hash_value = 37 * hash_value + key[i];
    }

    return hash_value;
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


template <typename HashObj>
class HashTable
{
public:
    explicit HashTable(int size = 23) : current_size_(0)
    {
        hash_list_.resize(size);
    }

    bool Contains(const HashObj& x) const
    {
        // 根据hash值查找hash表中对应的单元
        // 该单元是一个链表
        const list<HashObj>& which_list_ = hash_list_[MyHash(x)];
        return find(which_list_.begin(), which_list_.end(), x) != which_list_.end();
    }

    void MakeEmpty()
    {
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            hash_list_[i].clear();
        }
    }

    bool Insert(const HashObj& x)
    {
        list<HashObj>& which_list_ = hash_list_[MyHash(x)];
        if (find(which_list_.begin(), which_list_.end(), x) != which_list_.end())
        {
            return false;
        }

        which_list_.push_back(x);
        ++current_size_;

        // 再哈希
        if (current_size_ > hash_list_.size())
        {
            Rehash();
        }
        return true;
    }

    bool Remove(const HashObj& x)
    {
        list<HashObj>& which_list_ = hash_list_[MyHash(x)];
        list<HashObj>::iterator itor = find(which_list_.begin(), which_list_.end(), x);
        if (itor == which_list_.end())
        {
            return false;
        }

        which_list_.erase(itor);
        --current_size_;
        return true;
    }


    void Rehash()
    {
        vector<list<HashObj> > old_list = hash_list_;
        hash_list_.resize(NextPrime(old_list.size() * 2));
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            hash_list_[i].clear();
        }

        // 拷贝之前的元素
        current_size_ = 0;
        for (int i = 0; i < old_list.size(); ++i)
        {
            list<HashObj>::iterator itor = old_list[i].begin();
            while (itor != old_list[i].end())
            {
                Insert(*itor);
                ++itor;
            }
        }
    }

    void PrintTable()
    {
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            list<HashObj>& element_list = hash_list_[i];
            if (element_list.size() == 0)
                cout << "没有元素被映射到Hash表的第 " << i << " 个位置" << endl;
            else {
                cout << "映射到Hash表的第 " << i << "个位置的元素为: ";
                for (list<HashObj>::iterator itor = element_list.begin(); itor != element_list.end(); ++itor)
                {
                    cout << *itor << " ";
                }
                cout << endl;
            }
        }
    }

    // 成功平均查找长度
    void CalculateSuccessAverageSearchLength()
    {
        double success_average_search_length = 0;
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            list<HashObj>& element_list = hash_list_[i];
            if (element_list.size() > 0)
                success_average_search_length += (1 + element_list.size()) *  element_list.size() / 2;
        }
        success_average_search_length /= current_size_;
        cout << "成功平均查找长度为：" << success_average_search_length << endl;
    }

    // 不成功平均查找长度
    void CalculateUnSuccessAverageSearchLength()
    {
        // 使用的哈希函数为key MOD 12
        // 哈希值只可能为0-11，共12个哈希值
        int hash_count = 12;
        double unsuccess_average_search_length = 0;
        for (int i = 0; i < hash_count; ++i)
        {
            list<HashObj>& element_list = hash_list_[i];
            if (element_list.size() > 0)
                unsuccess_average_search_length += (element_list.size() + 1);
            else
                unsuccess_average_search_length += 1;
        }
        unsuccess_average_search_length /= hash_count;
        cout << "不成功平均查找长度为：" << unsuccess_average_search_length << endl;
    }
private:
    // 哈希函数
    int MyHash(const HashObj& x)
    {
        int hase_value = Hash(x);
        hase_value %= hash_list_.size();
        if (hase_value < 0)
            hase_value += hash_list_.size();

        return hase_value;
    }

private:
    int current_size_;

    // 分离链表法的hash表中
    vector<list<HashObj> > hash_list_;
};

#endif  // HASH_TABLE_H
