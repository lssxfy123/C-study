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
	// 这样做是为了防止溢出
    // 这样不会对最终结果产生影响：
    // 取模规则:(a + b) % p = (a % p + b % p) % p
    // 在下面的for循环中如果倒数第2个循环得到的值为sum
    // 不进行sum = sum % HASH_SIZE的操作
    // 则字符串的hashCode为(sum * base + d) % HASH_SIZE
    // 令 x = sum % HASH_SIZE，sum = n * HASH_SIZE + x
    // 则(sum * base + d) % HASH_SIZE = (n * HASH_SIZE * base + x * base + d) % HASH_SIZE
    // = ((n * HASH_SIZE * base) % HASH_SIZE + (x * base) % HASH_SIZE + d % HASH_SIZE) % HASH_SIZE
    // 根据模运算的特性(n * HASH_SIZE * base) % HASH_SIZE = 0
    // 则得出：(sum * base + d) % HASH_SIZE = ((x * base ) % HASH_SIZE + d % HASH_SIZE) % HASH_SIZE
    // 就相当于（x * base +d） % HASH_SIZE的结果
    // 所以每次循环中对sum进行取模运算对最终结果没有影响
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
