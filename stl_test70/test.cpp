// Copyright 2017.刘珅珅
// author：刘珅珅
// 非更易型算法6
#include "../include/algostuff.hpp"

int main(int argc, char* argv[])
{
    // all_of, any_of, none_of
    vector<int> coll;
    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll:   ");
    auto IsEven = [](int elem) {
        return elem % 2 == 0;
    };

    cout << boolalpha << "all even?:   "
        << all_of(coll.cbegin(), coll.cend(), IsEven) << endl;

    cout << boolalpha << "any even?:   "
        << any_of(coll.cbegin(), coll.cend(), IsEven) << endl;

    cout << "none even?:   "
        << none_of(coll.cbegin(), coll.cend(), IsEven) << endl;
    return 0;
}
