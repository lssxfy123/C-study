#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;

template<typename T>
inline void PrintElements(const T& coll, const string& optstr = "")
{
    cout << optstr.c_str();
    for (const auto& elem : coll)
    {
        cout << elem << ' ';
    }
    cout << endl;
}

#endif
