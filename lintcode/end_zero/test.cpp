// Copyright 2018.���|�|
// author�����|�|
// n!β����0����
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

// �жϳ�n���ж��ٸ�5����n����(25, 125)
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
