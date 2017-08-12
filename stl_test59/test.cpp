// Copyright 2017.刘珅珅
// author：刘珅珅
// function adapter:bind()的基本功能
#include <algorithm>
#include <functional>
#include <locale>
#include <iostream>
#include "../include/print.hpp"
using namespace std;
using namespace std::placeholders;

char MyToupper(char c)
{
    locale loc;
    return use_facet<ctype<char>>(loc).toupper(c);
}

int main(int argc, char* argv[])
{
    // bind()基本功能
    auto plus10 = bind(plus<int>(), _1, 10);
    cout << "+10:     " << plus10(7) << endl;

    // 组合两个STL预定义的functon object
    auto plus10times2 = bind(multiplies<int>(), bind(plus<int>(), _1, 10), 2);
    cout << "(+10) * 2:    " << plus10times2(7) << endl;

    auto pow3 = bind(multiplies<int>(), bind(multiplies<int>(), _1, _1), _1);
    cout << "x*x*x:   " << pow3(7) << endl;

    auto inversDivide = bind(divides<double>(), _2, _1);
    cout << "invdiv:    " << inversDivide(49, 7) << endl;

    // 调用全局函数
    string s("Internationalization");
    string sub("Nation");

    string::iterator pos 
        = search(s.begin(), s.end(),  // string to search in
            sub.begin(), sub.end(),  // substring to search
            bind(equal_to<char>(), bind(MyToupper, _1),  // 比较标准
                bind(MyToupper, _2)));
    if (pos != s.end())
    {
        cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;
    }
    return 0;
}
