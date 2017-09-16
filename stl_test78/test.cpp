// Copyright 2017.刘珅珅
// author：刘珅珅
// 已排序区间算法2
#include "../include/algostuff.hpp"

int main(int argc, char* argv[])
{
    // merge
    list<int> coll1;
    set<int> coll2;

    InsertElements(coll1, 1, 6);
    InsertElements(coll2, 3, 8);
    PrintElements(coll1, "coll1:   ");
    PrintElements(coll2, "coll2:   ");
    cout << "merged:  ";
    merge(coll1.cbegin(), coll1.cend(),
        coll2.cbegin(), coll2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << endl;

    // set_union
    vector<int> c1 = {1, 2, 2, 4, 6, 7, 7, 9};
    deque<int> c2 = {2, 2, 2, 3, 6, 6, 8, 9};
    PrintElements(c1, "c1:  ");
    PrintElements(c2, "c2:  ");

    cout << "set_union():     ";
    set_union(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << endl;

    // set_intersection
    PrintElements(c1, "c1:  ");
    PrintElements(c2, "c2:  ");
    cout << "set_intersection():     ";
    set_intersection(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << endl;

    // set_difference
    PrintElements(c1, "c1:  ");
    PrintElements(c2, "c2:  ");
    cout << "set_difference():    ";
    set_difference(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << endl;

    // set_symmetric_difference
    PrintElements(c1, "c1:  ");
    PrintElements(c2, "c2:  ");
    cout << "set_symmetric_difference():    ";
    set_symmetric_difference(c1.cbegin(), c1.cend(),
        c2.cbegin(), c2.cend(),
        ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
