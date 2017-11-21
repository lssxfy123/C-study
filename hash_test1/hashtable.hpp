#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// C++11�д��������hash����
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

// ����n���������
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

        // �ٹ�ϣ
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

        // ����֮ǰ��Ԫ��
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

    // �ɹ�ƽ�����ҳ���
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
        cout << "�ɹ�ƽ�����ҳ���Ϊ��" << success_average_search_length << endl;
    }

    // ���ɹ�ƽ�����ҳ���
    void CalculateUnSuccessAverageSearchLength()
    {
        // ʹ�õĹ�ϣ����Ϊkey MOD 12
        // ��ϣֵֻ����Ϊ0-11����12����ϣֵ
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
        cout << "���ɹ�ƽ�����ҳ���Ϊ��" << unsuccess_average_search_length << endl;
    }
private:
    // ��ϣ����
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

    // ����������hash����
    vector<list<HashObj> > hash_list_;
};

#endif  // HASH_TABLE_H
