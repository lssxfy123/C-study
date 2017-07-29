#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;

// 解决vs上<<无法直接输出string类型的问题
namespace std
{
    ostream& operator <<(ostream& os, const string& src)
    {
        return os << src.c_str();
    }
}

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
