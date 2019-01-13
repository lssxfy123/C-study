// Copyright 2019.���|�|
// author�����|�|
// hash������ʵ��
#include <iostream>
#include <vector>
#include <cmath>
#include "../../include/print.hpp"
using namespace std;

// https://www.cnblogs.com/lca1826/p/6748372.html
long long quick_power(long long x, long long n)
{
    // n = 5,ת��Ϊ������Ϊ101, n = 2^2 * 1 + 2^1 * 0 + 2^0 * 1
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
    // ����"abcd"����
    // sum = a
    // sum = a * base + b
    // sum = (a * base + b) * base + c
    // sum = ((a * base + b) * base + c) * base + d
    // ÿ��ѭ������ʱ����sum = sum % HASH_SIZE
    // ������������ս������Ӱ�죺
    // �� x = sum % HASH_SIZE����
    // sum = n * HASH_SIZE + x
    // ����ģ���������(n * HASH_SIZE * base) % HASH_SIZE = 0
    // (sum * base) % HASH_SIZE = (x * base ) % HASH_SIZE
    for (int i = 0; i < key.length(); ++i)
    {
        // lLLת��Ϊlong long����ֹ���
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
