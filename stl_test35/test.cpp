// Copyright 2017.刘珅珅
// author：刘珅珅
// 迭代器适配器：反向迭代器适配器
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll;
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    // 反向迭代器
    copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
