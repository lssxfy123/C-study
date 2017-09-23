// Copyright 2017.���|�|
// author�����|�|
// ������ʽ������
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
    sregex_iterator end;  // Ĭ�ϵĽ�β
    for (; pos != end; ++pos)
    {
        cout << "match:   " << pos->str() << endl;
        cout << "  tag:  " << pos->str(1) << endl;
        cout << "  value:  " << pos->str(2) << endl;
    }
    return 0;
}
