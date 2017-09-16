// Copyright 2017.刘珅珅
// author：刘珅珅
// 已排序区间算法
#include "../include/algostuff.hpp"
int main(int argc, char* argv[])
{
    // binary_search
    list<int> coll;
    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll:   ");

    // check existence of element with value 5
    if (binary_search(coll.cbegin(),coll.cend(), 5))
    {
        cout << "5 is present" << endl;
    }
    else {
        cout << "5 is not present" << endl;
    }
    cout << endl;

    // includes
    list<int> coll1;
    vector<int> search;
    InsertElements(coll1, 1, 9);
    PrintElements(coll1, "coll1:  ");

    search.push_back(3);
    search.push_back(4);
    search.push_back(7);
    PrintElements(search, "search:  ");

    if (includes(coll1.cbegin(), coll1.cend(),
        search.cbegin(), search.cend()))
    {
        cout << "all elements of search are also in coll1" << endl;
    }
    else {
        cout << "not all elements of search are also in coll1" << endl;
    }
    cout << endl;

    // lower_bound, upper_bound
    list<int> coll2;
    InsertElements(coll2, 1, 9);
    InsertElements(coll2, 1, 9);
    coll2.sort();
    PrintElements(coll2, "coll2:  ");

    // print first and last position 5 could get inserted
    auto first_pos = lower_bound(coll2.cbegin(), coll2.cend(), 5);
    auto last_pos = upper_bound(coll2.cbegin(), coll2.cend(), 5);
    cout << "5 could get position "
        << distance(coll2.cbegin(), first_pos) + 1
        << " up to "
        << distance(coll2.cbegin(), last_pos) + 1
        << "without breaking the sorting" << endl;

    // insert 3 at the first possible position
    // without breaking the sorting
    coll2.insert(lower_bound(coll2.begin(), coll2.end(), 3), 3);

    // insert 7 at the last possible position
    // without breaking the sorting
    coll2.insert(upper_bound(coll2.begin(), coll2.end(), 7), 7);
    PrintElements(coll2, "coll2:  ");
    return 0;
}
