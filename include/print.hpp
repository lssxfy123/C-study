#ifndef PRINT_H
#define PRINT_H

#include <iostream>
using namespace std;

// ���vs��<<�޷�ֱ�����string���͵�����
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
