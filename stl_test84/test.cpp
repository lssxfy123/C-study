// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// stringÓëµü´úÆ÷
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    string s("The zip code of Braunschweig in Germany is 38100");
    cout << "original:  " << s << endl;

    // lowercase all characters
    transform(s.cbegin(), s.cend(),
        s.begin(),
        [](char c) {
        return tolower(c);
    });
    cout << "lowered:   " << s << endl;

    // uppercase all characters
    transform(s.cbegin(), s.cend(),
        s.begin(),
        [](char c) {
        return toupper(c);
    });
    cout << "uppered:   " << s << endl;
    cout << endl;

    const string hello("Hello, how are you?");

    string s1(hello.cbegin(), hello.cend());

    for (char c : s1)
    {
        cout << c;
    }
    cout << endl;

    reverse(s1.begin(), s1.end());
    cout << "reverse:   " << s1 << endl;

    sort(s1.begin(), s1.end());
    cout << "ordered:   " << s1 << endl;
    return 0;
}
