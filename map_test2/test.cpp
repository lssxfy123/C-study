// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// mapÈİÆ÷µÄ²âÊÔ
#include <iostream>
#include "../include/print.hpp"
#include <map>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    char head[7] = { 0 };
    head[0] = 'h';
    head[1] = 'h';
    head[2] = 'h';
    head[3] = 'h';
    head[4] = 'h';
    head[5] = 'h';
    head[6] = 'h';

    map<string, int> map1;
    map1[head]++;

    int index = map1[head];

    cout << index << endl;  // index = 1
    return 0;
}
