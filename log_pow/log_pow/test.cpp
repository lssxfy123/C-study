// Copyright 2015.Áõ«|«|
// author£ºÁõ«|«|
// ÃİÔËËã

#include <iostream>
using namespace std;

bool IsEven(long x)
{
    if (x % 2 == 0)
    {
        return true;
    }
    return false;
}

long pow(long x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return x;
    }

    if (IsEven(x))
    {
        return pow(x * x, n / 2);
    }
    else
    {
        return pow(x * x, n / 2) * x;
    }
}

int main(int argc, char* argv[])
{
    return 0;
}
