// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// N»ÊºóÎÊÌâ
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

void queen(long upper_column, long row, long left, long right, int& sum);
int totalNQueens(int n) {
    // write your code here
    long upper_column = 1;
    upper_column = (upper_column << n) - 1;
    vector<vector<string>> result(n, vector<string>(n, ""));
    int sum = 0;
    queen(upper_column, 0, 0, 0, sum);
    return sum;
}

void queen(long upper_column, long row, long left, long right, int& sum)
{
    if (row != upper_column)
    {
        long pos = upper_column & ~(row | left | right);
        while (pos)
        {
            long p = pos & (~pos + 1);
            pos -= p;
            queen(upper_column, row + p, (left + p) << 1, (right + p) >> 1, sum);
        }
    }
    else
    {
        ++sum;
    }
}

int main(int argc, char* argv[])
{
    cout << totalNQueens(12) << endl;
    return 0;
}
