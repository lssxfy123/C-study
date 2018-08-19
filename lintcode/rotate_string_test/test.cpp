// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// Ðý×ª×Ö·û´®
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

void rotateString(string &str, int offset) {
    // write your code here
    if (str.length() == 0)
    {
        return;
    }
    offset = offset % str.length();
    if (offset == 0)
    {
        return;
    }

    str = str.substr(str.length() - offset, offset)
        + str.substr(0, str.length() - offset);
}


int main(int argc, char* argv[])
{
    string str = "abcdefg";
    cout << "original: " << str << endl;
    rotateString(str, -1);
    cout << "rotate: " << str << endl;
    return 0;
}
