// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数作为算法的实参2：单参判断式
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// 判断是否为质数
bool IsPrime(int number)
{
    number = abs(number);
    if (number == 0 || number == 1)
    {
        return false;
    }

    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor)
    {
    }

    return divisor == 1;
}

int main(int argc, char* argv[])
{
    list<int> coll;
    for (int i = 24; i <= 30; ++i)
    {
        coll.push_back(i);
    }

    // 查找第1个质数
    auto pos = find_if(coll.cbegin(), coll.cend(), IsPrime);
    if (pos != coll.end())
    {
        cout << *pos << " is first prime number found" << endl;
    }
    else
    {
        cout << "no prime number found" << endl;
    }
    return 0;
}
