// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：deque
#include <algorithm>
#include <functional>
#include <deque>
#include <iostream>
#include <iterator>
#include "../include/print.hpp"
using namespace std;

// 解决vs上<<无法直接输出string类型的问题
namespace std
{
    ostream& operator <<(ostream& os, const string& src)
    {
        return os << src.c_str() << endl;
    }
}

int main(int argc, char* argv[])
{
    deque<string> coll;
    coll.assign(3, "string");
    coll.push_back("last string");
    coll.push_front("first string");
    cout << "original: " << endl;
    copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    cout << endl;

    cout << "remove first and last: " << endl;
    coll.pop_front();
    coll.pop_back();

    for (deque<string>::size_type i = 1; i < coll.size(); ++i)
    {
        coll[i] = "another " + coll[i];
    }

    copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    cout << endl;

    cout << "resize: " << endl;
    // 在末端插入"resize string"或删除末端元素
    // 使size() = 4
    coll.resize(4, "resize string");
    copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
