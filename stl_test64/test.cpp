// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// for_each()

#include "../include/algostuff.hpp"
int main(int argc, char* argv[])
{
    vector<int> coll;
    InsertElements(coll, 1, 9);
    for_each(coll.begin(), coll.end(), [](int& elem) {
        elem += 10;
    });
    PrintElements(coll);

    for_each(coll.begin(), coll.end(), [=](int& elem) {
        elem += *coll.begin();
    });
    PrintElements(coll);
    return 0;
}
