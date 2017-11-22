// Copyright 2015.刘珅珅
// author：刘珅珅
// 运行时间的实际计算

#include <iostream>
using namespace std;

int sum1(int n)
{
    int sum = 0;
    for (int i = 0; i != n; ++i)
    {
        sum += i;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int n = 10000;
    sum1(n);
    return 0;
}
