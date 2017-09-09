// Copyright 2017.刘珅珅
// author：刘珅珅
// 排序算法
#include "../include/algostuff.hpp"

bool LessLength(const string& s1, const string& s2)
{
    return s1.length() < s2.length();
}

int main(int argc, char* argv[])
{
    // sort
    deque<int> coll;
    InsertElements(coll, 1, 9);
    InsertElements(coll, 1, 9);

    PrintElements(coll, "on entry:   ");

    sort(coll.begin(), coll.end());
    PrintElements(coll, "sorted:   ");

    sort(coll.begin(), coll.end(), greater<int>());
    PrintElements(coll, "sorted > :   ");
    cout << endl;

    // stable_sort
    vector<string> coll1 = {"1xxx", "2x", "3x", "4x", "5xx",
                                          "6xxxx", "7xx", "8xxx", "10xxx",
                                          "11", "12", "13", "14xx", "15", "16", "17"};
    vector<string> coll2(coll1);
    PrintElements(coll1, "on entry:\n");

    // 在visual studio中二者貌似没区别
    sort(coll1.begin(), coll1.end(), LessLength);
    stable_sort(coll2.begin(), coll2.end(), LessLength);

    PrintElements(coll1, "\nwith sort(): \n");
    PrintElements(coll2, "\nwith stable_sort():\n");
    cout << endl;

    // partial_sort
    deque<int> coll3;
    InsertElements(coll3, 3, 7);
    InsertElements(coll3, 2, 6);
    InsertElements(coll3, 1, 5);
    PrintElements(coll3, "coll3:  ");

    // sort until the first five elements are sorted
    // 对整个序列排序，只需要前5个已序
    partial_sort(coll3.begin(), coll3.begin() + 5, coll3.end());
    PrintElements(coll3, "after first five elements sorted:  ");

    //sort inversely until the first five elements are sorted
    partial_sort(coll3.begin(), coll3.begin() + 5,
        coll3.end(), greater<int>());
    PrintElements(coll3, "after first five elements:  ");
    return 0;
}
