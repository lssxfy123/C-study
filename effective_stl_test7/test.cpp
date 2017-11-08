// Copyright 2017.刘珅珅
// author：刘珅珅
// 指定关联容器中指针的比较类型
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

// 更为通用的指针比较类型
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
    // 第2个参数是指定的指针的比较类型
    set<string*, StringPtrLess> string_set;
    //set<string*, DereferenceLess> string_set;

    // 如果未指定比较类型，则会按照指针地址的大小排序
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
