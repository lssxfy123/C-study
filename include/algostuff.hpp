#ifndef ALGOSTUFF_H
#define ALGOSTUFF_H

#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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
inline void InsertElements(T& coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
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

template<typename T>
inline void PrintMappedElements(const T& coll,
    const string& optcstr = "")
{
    cout << optcstr;
    for (auto elem : coll)
    {
        cout << '[' << elem.first << ',' << elem.second << "] ";
    }
    cout << endl;
}

#endif
