// Copyright 2017.刘珅珅
// author：刘珅珅
// 正则表达式1
#include <iostream>
#include <regex>
#include "../include/print.hpp"
using namespace std;

void out(bool b)
{
    cout << (b ? "found" : "not found") << endl;
}

int main(int argc, char* argv[])
{
    regex reg1("<.*>.*</.*>");
    string source = "<tag>value</tag>";
    bool found = regex_match(source, reg1);
    out(found);

    regex reg2("<(.*)>.*</\\1>");
    found = regex_match(source, reg2);
    out(found);
    return 0;
}
