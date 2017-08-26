// Copyright 2017.刘珅珅
// author：刘珅珅
// 非更易型算法4
#include "../include/algostuff.hpp"

void PrintList(const list<int>& list)
{
    PrintElements(list);
}

bool LessForCollection(const list<int>& list1, const list<int>& list2)
{
    return lexicographical_compare(list1.cbegin(), list1.cend(),
        list2.cbegin(), list2.cend());
}

int main(int argc, char* argv[])
{
    list<int> c1, c2, c3, c4;
    InsertElements(c1, 1, 5);
    c4 = c3 = c2 = c1;
    c1.push_back(7);
    c3.push_back(2);
    c3.push_back(0);
    c4.push_back(2);

    vector<list<int>> cc;
    cc.insert(cc.begin(), {c1, c2, c3, c4, c3, c1, c4, c2});
    cout << "original:  " << endl;
    for_each(cc.cbegin(), cc.cend(), PrintList);
    cout << endl;

    cout << "sort:  " << endl;
    sort(cc.begin(), cc.end(), LessForCollection);
    for_each(cc.cbegin(), cc.cend(), PrintList);
    return 0;
}
