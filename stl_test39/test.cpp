// Copyright 2017.刘珅珅
// author：刘珅珅
// Lambda作为算法的实参
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    deque<int> coll = { 1, 3, 19, 5, 13, 7, 11, 2, 17 };
    int x = 5;
    int y = 12;

    // Lambda表达式作为算法实参
    // [=]传值方式
    auto pos = find_if(coll.cbegin(), coll.cend(), [=](int i) {return i > x && i < y; });

    if (pos != coll.end())
    {
        cout << "first elem > 5 and < 12: " << *pos << endl;
    }
    return 0;
}
