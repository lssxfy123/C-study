// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ×Ö·û´®
#include <iostream>
#include <string>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    const string delims(" \t,.;");
    string line;

    while (getline(cin, line))
    {
        string::size_type begin_index, end_index;

        begin_index = line.find_first_not_of(delims);

        while (begin_index != string::npos)
        {
            end_index = line.find_first_of(delims, begin_index);
            if (end_index == string::npos)
            {
                end_index = line.length();
            }

            for (int i = end_index - 1; i >= static_cast<int>(begin_index); --i)
            {
                cout << line[i];
            }
            cout << ' ';

            begin_index = line.find_first_not_of(delims, end_index);
        }
        cout << endl;
    }
    return 0;
}
