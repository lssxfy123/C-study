// Copyright 2017.刘珅珅
// author：刘珅珅
// STL Predicate
#include <algorithm>
#include <iostream>
#include <list>
#include "../include/print.hpp"
using namespace std;

class Nth {
public:
    Nth(int n) : nth_(n), count_(0) {
    }

    // Predicate
    bool operator() (int) {
        return ++count_ == nth_;
    }

private:
    int nth_;
    int count_;
};

int main(int argc, char* argv[])
{
    list<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintElements(coll, "original:    ");

    // 在Visual Studio上这个没问题
    list<int>::iterator pos = remove_if(coll.begin(), coll.end(), Nth(3));
    coll.erase(pos, coll.end());
    PrintElements(coll, "3rd removed:   ");
    return 0;
}
