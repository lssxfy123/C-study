// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ÈÝÆ÷£ºÎÞÐòÈÝÆ÷£º²é¿´hashÈÝÆ÷ÄÚ²¿×´Ì¬
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include "../include/buckets.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    unordered_set<int> intset = {1, 2, 3, 5, 7, 11, 13, 17, 19};

    PrintHashTableState(intset);

    cout << "insert some numbers" << endl;
    intset.insert({ -7, 17, 33, 4 });
    PrintHashTableState(intset);

    unordered_multimap<string, string> dict = {
        {"day", "Tag"},
        {"strange", "fremd"},
        {"car", "Auto"},
        {"smart", "elegant"},
        {"trait", "Merkmal"},
        {"strange", "seltsam"}
    };
    PrintHashTableState(dict);

    cout << "insert some pair" << endl;
    dict.insert({ {"smart", "raffiniert"}, {"smart", "klug"}, {"clever", "raffiniert"} });
    PrintHashTableState(dict);

    cout << "set max load factor" << endl;
    dict.max_load_factor(0.7f);
    PrintHashTableState(dict);

    return 0;
}
