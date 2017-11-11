// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// lexicographical_compare±È½Ï
#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

bool CharLess(char c1, char c2)
{
    return tolower(static_cast<unsigned char>(c1))
        < tolower(static_cast<unsigned char>(c2));
}

bool StringCompare(const string& s1, const string& s2)
{
    return lexicographical_compare(s1.begin(), s1.end(),
        s2.begin(), s2.end(),
        CharLess);
}

int main(int argc, char* argv[])
{
    string s1 = "lss";
    string s2 = "Lss";

    if (StringCompare(s1, s2))
    {
        cout << "Less" << endl;
    }
    else
    {
        cout << "Not less" << endl;
    }
    return 0;
}
