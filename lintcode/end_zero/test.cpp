// Copyright 2018.刘珅珅
// author：刘珅珅
// n!尾部的0个数
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

// 判断出n中有多少个5及其n次幂(25, 125)
long long TrailingZeros(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n / 5 + TrailingZeros(n / 5);
    }
}

int main(int argc, char* argv[])
{
    cout << TrailingZeros(10000) << endl;
   
    return 0;
}
