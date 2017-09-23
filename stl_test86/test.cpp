// Copyright 2017.刘珅珅
// author：刘珅珅
// 正则表达式匹配细节
#include <iomanip>
#include <iostream>
#include <regex>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    string data = "XML tag: <tag-name>the value </tag-name>.";
    cout << "data:        " << data << endl;
    cout << endl;

    smatch m;  // for returned details of the match
    // regex_search：部分匹配
    bool found = regex_search(data, m,
        regex("<(.*)>(.*)</(\\1)>"));

    // print match details
    cout << "m.empty():    " << boolalpha << m.empty() << endl;
    cout << "m.size():   " << m.size() << endl;

    if (found)
    {
        // 匹配合格的所有字符
        cout << "m.str():   " << m.str() << endl;

        // 匹配合格的所有字符长度
        cout << "m.length():   " << m.length() << endl;

        // 匹配合格的整体字符的位置
        cout << "m.position():   " << m.position() << endl;

        // 第1个匹配合格的字符前的所有字符
        cout << "m.prefix().str():   " << m.prefix().str() << endl;

        // 最后一个匹配合格的字符后的所有字符
        cout << "m.suffix().str():   " << m.suffix().str() << endl;
        cout << endl;

        // iterating over all matches(using the match index)
        for (int i = 0; i < m.size(); ++i)
        {
            cout << "m[" << i << "].str():   " << m[i].str() << endl;
            cout << "m.str(" << i << "):   " << m.str(i) << endl;
            cout << "m.position(" << i << "):   " << m.position(i)
                << endl;
        }
        cout << endl;

        // iterating over all matches(using iterators)
        cout << "matches:   " << endl;
        for (auto pos = m.begin(); pos != m.end(); ++pos)
        {
            cout << " " << *pos << " ";
            cout << "(length: " << pos->length() << ")" << endl;
        }
    }
    return 0;
}
