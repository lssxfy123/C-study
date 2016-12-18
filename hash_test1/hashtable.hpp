#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int hash(int key)
{
    return key % 10;
}

int hash(const string& key)
{
    int hash_value = 0;
    for (int i = 0; i < key.length(); ++i)
    {
        hash_value = 37 * hash_value + key[i];
    }

    return hash_value;
}

template <typename HashObj>
class HashTable
{
public:
    explicit HashTable(int size = 101) : current_size_(size)
    {
        hash_list_.resize(size);
    }

    bool Contains(const HashObj& x) const
    {
        // ����hashֵ����hash���ж�Ӧ�ĵ�Ԫ
        // �õ�Ԫ��һ������
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

        // ��ʱ�������ٹ�ϣ
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

        which_list_.erase(x);
        --current_size_;
        return true;
    }

    void PrintTable()
    {
        for (int i = 0; i < hash_list_.size(); ++i)
        {
            list<HashObj>& element_list = hash_list_[i];
            if (element_list.size() == 0)
                cout << "û��Ԫ�ر�ӳ�䵽Hash��ĵ� " << i << " ��λ��" << endl;
            else {
                cout << "ӳ�䵽Hash��ĵ� " << i << "��λ�õ�Ԫ��Ϊ: ";
                for (list<HashObj>::iterator itor = element_list.begin(); itor != element_list.end(); ++itor)
                {
                    cout << *itor << " ";
                }
                cout << endl;
            }
        }
    }
private:
    int MyHash(const HashObj& x)
    {
        int hase_value = hash(x);
        hase_value %= hash_list_.size();
        if (hase_value < 0)
            hase_value += hash_list_.size();

        return hase_value;
    }

private:
    int current_size_;

    // ����������hash����
    vector<list<HashObj> > hash_list_;
};

#endif
