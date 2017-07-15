// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数作为算法的实参
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

int square(int value)
{
    return value * value;
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

int main(int argc, char* argv[])
{
    set<int> coll1;
    vector<int> coll2;

    for (int i = 1; i <= 9; ++i)
    {
        coll1.insert(i);
    }

    // 自定义的square作为算法的实参
    transform(coll1.cbegin(), coll1.cend(), back_inserter(coll2), square);

    PrintElements(coll1, "initialized:   ");
    PrintElements(coll2, "squared:    ");
    return 0;
}
