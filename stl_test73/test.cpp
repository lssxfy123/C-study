// Copyright 2017.刘珅珅
// author：刘珅珅
// 更易型算法3
#include "../include/algostuff.hpp"
using namespace std::placeholders;
int main(int argc, char* argv[])
{
    // replace
    list<int> coll;
    InsertElements(coll, 2, 7);
    InsertElements(coll, 4, 9);
    PrintElements(coll, "coll:   ");

    // replace all elements with value 6 with 42
    replace(coll.begin(), coll.end(), 6, 42);
    PrintElements(coll, "coll:   ");

    // replace all elements with value less than 5 with 0
    replace_if(coll.begin(), coll.end(),
        [](int elem) {
        return elem < 5;
    },
        0);
    PrintElements(coll, "coll:   ");
    cout << endl;

    // replace_copy
    list<int> coll1;
    InsertElements(coll1, 2, 6);
    InsertElements(coll1, 4, 9);
    PrintElements(coll1, "coll1:   ");

    // print all elements with value 5 replaced with 55
    replace_copy(coll1.cbegin(), coll1.cend(),  //source
        ostream_iterator<int>(cout, " "),   // destination
        5,                                                    // oldValue
        55);                                                // newValue
    cout << endl;

    // print all elements with a value less than 5 replaced with 42
    replace_copy_if(coll1.cbegin(), coll1.cend(),
        ostream_iterator<int>(cout, " "),
        bind(less<int>(), _1, 5),
        42);
    cout << endl;
    return 0;
}
