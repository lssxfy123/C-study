// Copyright 2017.刘珅珅
// author：刘珅珅
// 非更易型算法3
#include "../include/algostuff.hpp"

bool BothEvenOrOdd(int elem1, int elem2)
{
    return elem1 % 2 == elem2 % 2;
}

int main(int argc, char* argv[])
{
    // equal
    vector<int> coll1;
    list<int> coll2;
    InsertElements(coll1, 1, 7);
    InsertElements(coll2, 3, 9);
    PrintElements(coll1, "coll1:   ");
    PrintElements(coll2, "coll2:   ");
    if (equal(coll1.begin(), coll1.end(), coll2.begin()))
    {
        cout << "coll1 == coll2" << endl;
    }
    else
    {
        cout << "coll1 != coll2" << endl;
    }

    if (equal(coll1.begin(), coll1.end(), coll2.begin(), BothEvenOrOdd))
    {
        cout << "even and odd elements correspond" << endl;
    }
    else
    {
        cout << "even and odd elements do not correspond" << endl;
    }
    cout << endl;

    // is_permutation
    vector<int> coll3 = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> coll4 = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10};
    deque<int> coll5 = {11, 12, 13, 19, 18, 17, 16, 15, 14, 11};
    PrintElements(coll3, "coll3:   ");
    PrintElements(coll4, "coll4:   ");
    PrintElements(coll5, "coll5:   ");

    if (is_permutation(coll3.cbegin(), coll3.cend(),  // first range
        coll4.cbegin()))  // second range
    {
        cout << "coll3 and coll4 have equal elements" << endl;
    }
    else
    {
        cout << "coll3 and coll4 don't have equal elements" << endl;
    }

    if (is_permutation(coll3.cbegin(), coll3.cend(),
        coll5.cbegin(), BothEvenOrOdd))
    {
        cout << "numbers of even and odd elements match" << endl;
    }
    else
    {
        cout << "numbers of even and odd elements don't match" << endl;
    }
    cout << endl;

    // mismatch
    vector<int> coll6 = {1, 2, 3, 4, 5, 6};
    list<int> coll7 = {1, 2, 4, 8, 16, 3};
    PrintElements(coll6, "coll6:   ");
    PrintElements(coll7, "coll7:   ");
    auto values = mismatch(coll6.cbegin(), coll6.cend(), coll7.cbegin());
    if (values.first == coll6.end())
    {
        cout << "no mismatch" << endl;
    }
    else
    {
        cout << "first mismatch: "
            << *values.first << " and "
            << *values.second << endl;
    }

    values = mismatch(coll6.cbegin(), coll6.cend(), coll7.cbegin(), less_equal<int>());
    if (values.first == coll6.end())
    {
        cout << "always less-or-equal" << endl;
    }
    else
    {
        cout << "not less-or-equal: "
            << *values.first << " and "
            << *values.second << endl;
    }
    return 0;
}
