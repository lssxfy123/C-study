// Copyright 2017.刘珅珅
// author：刘珅珅
// 正则表达式迭代器
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <regex>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    string data = "<person>\n"
        "<first>Nico</first>\n"
        "<last>Josuttis</last>\n"
        "</person>\n";
    regex reg("<(.*)>(.*)</(\\1)>");
    sregex_iterator pos(data.cbegin(), data.cend(), reg);
    sregex_iterator end;  // 默认的结尾
    for (; pos != end; ++pos)
    {
        cout << "match:   " << pos->str() << endl;
        cout << "  tag:  " << pos->str(1) << endl;
        cout << "  value:  " << pos->str(2) << endl;
    }
    return 0;
}
