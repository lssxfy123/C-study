// Copyright 2017.���|�|
// author�����|�|
// ָ������������ָ��ıȽ�����
#include <iostream>
#include <set>
#include "../include/print.hpp"
using namespace std;

struct StringPtrLess :
    public binary_function<const string*, const string*, bool>
{
    bool operator ()(const string* ps1, const string* ps2) const
    {
        return *ps1 < *ps2;
    }
};

// ��Ϊͨ�õ�ָ��Ƚ�����
struct DereferenceLess
{
    template<typename PtrType>
    bool operator() (PtrType pt1, PtrType pt2) const
    {
        return *pt1 < *pt2;
    }
};

int main(int argc, char* argv[])
{
    // ��2��������ָ����ָ��ıȽ�����
    set<string*, StringPtrLess> string_set;
    //set<string*, DereferenceLess> string_set;

    // ���δָ���Ƚ����ͣ���ᰴ��ָ���ַ�Ĵ�С����
    //set<string*> string_set;
    string_set.insert(new string("Anteater"));
    string_set.insert(new string("Wombat"));
    string_set.insert(new string("Lemur"));
    string_set.insert(new string("Penguin"));

    for (auto i = string_set.begin(); i != string_set.end(); ++i)
    {
        cout << **i << endl;
    }
    return 0;
}
