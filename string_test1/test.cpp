// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ×Ö·û´®Ê×Î²È¥¿Õ¸ñ
#include <iostream>
#include "../include/print.hpp"
using namespace std;
void TrimLead(string& str)
{
    string::iterator it = str.begin();
    for (; it != str.end(); ++it)
    {
        if (!isspace(*it))
            break;
    }

    str.erase(str.begin(), it);
}
void TrimTrail(string& str)
{
    string::reverse_iterator it = str.rbegin();
    for (; it != str.rend(); ++it)
    {
        if (!isspace(*it))
            break;
    }
    
    str.erase(it.base(), str.end());
}

int main(int argc, char* argv[])
{
    string str = "    ab  c";
    cout << "original str: " << endl;
    cout << str << endl;
    TrimLead(str);
    cout << "trim lead" << endl;
    cout << str << endl;
    cout << endl;

    string str1 = "abc d    ";
    TrimTrail(str1);
    return 0;
}
