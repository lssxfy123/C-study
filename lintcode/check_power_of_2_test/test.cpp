// Copyright 2018.刘珅珅
// author：刘珅珅
// O(1)时间检测n是否为2的幂次
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

bool checkPowerOf2(int n) {
    // write your code here
    if (n <= 0)
    {
        return false;
    }

    // 如果n为2的幂次，则其在二进制上只有1位为1，其余为0
    // n - 1就会发生借位现象，导致原本为1的位变成0，
    // n & (n - 1)肯定为0
    return (n & (n - 1)) == 0;

}

int main(int argc, char* argv[])
{
    return 0;
}
