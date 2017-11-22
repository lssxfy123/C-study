// Copyright 2015.
// author：刘珅珅
// 最大公因数gcd

#include <iostream>
using namespace std;

// 求两个数的最大公因数
// 假设m>=n
// 如果n>m，第一次迭代将交换两个数
long gcd(long m, long n)
{
    while (n != 0)
    {
        long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main(int argc, char* argv[])
{
    cout << gcd(255, 4) << endl;
    return 0;
}
