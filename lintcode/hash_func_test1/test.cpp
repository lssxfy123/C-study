// Copyright 2019.刘珅珅
// author：刘珅珅
// hash函数的实现
#include <iostream>
#include <vector>
#include <cmath>
#include "../../include/print.hpp"
using namespace std;

// https://www.cnblogs.com/lca1826/p/6748372.html
long long quick_power(long long x, long long n)
{
    // n = 5,转换为二进制为101, n = 2^2 * 1 + 2^1 * 0 + 2^0 * 1
    // x ^ n = x ^ (2^2) * x ^ (2^0)
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = res * x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

int hashCode(string &key, int HASH_SIZE) {
    // write your code here
    if (HASH_SIZE == 0 || key.length() == 0)
    {
        return 0;
    }

    const int base = 33;
    int sum = 0;
    // 对于"abcd"而言
    // sum = a
    // sum = a * base + b
    // sum = (a * base + b) * base + c
    // sum = ((a * base + b) * base + c) * base + d
    // 每次循环都及时计算sum = sum % HASH_SIZE
    // 这样不会对最终结果产生影响：
    // 令 x = sum % HASH_SIZE，则
    // sum = n * HASH_SIZE + x
    // 根据模运算的特性(n * HASH_SIZE * base) % HASH_SIZE = 0
    // (sum * base) % HASH_SIZE = (x * base ) % HASH_SIZE
    for (int i = 0; i < key.length(); ++i)
    {
        // lLL转换为long long，防止溢出
        sum = 1LL * sum * base + key[i];
        sum = sum % HASH_SIZE;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    string key = "abcd";
    string key1 = "abcdefghijk";
    string key2 = "abcdefghijklmn";
    cout << hashCode(key, 100) << endl;
    cout << hashCode(key1, 1000) << endl;
    cout << hashCode(key2, 1000) << endl;
    return 0;
}
