// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// erase-removeÉ¾³ý
#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vec;
    vec.reserve(10);
    for (int i = 1; i <= 10; ++i)
    {
        vec.push_back(i);
    }

    vec[3] = vec[5] = vec[9] = 99;
     vector<int>::iterator new_end = std::remove(vec.begin(), vec.end(), 99);
    cout << "size = " << vec.size() << endl;
    PrintElements(vec, "After remove : ");
    cout << endl;

    vec.erase(new_end, vec.end());
    cout << "size = " << vec.size() << endl;
    PrintElements(vec, "After erase : ");
    return 0;
}
