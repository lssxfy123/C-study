// Copyright 2015.
// author£ºÁõ«|«|
// ×Ô¶¨ÒåListÈİÆ÷

#include <iostream>
#include <list>
using namespace std;

#include "List.hpp"

int main(int argc, char* argv[])
{
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    int k = list1.back();

    cout << k << endl;
    return 0;
}
