// Copyright 2015.
// author�����|�|
// �������gcd

#include <iostream>
using namespace std;

// �����������������
// ����m>=n
// ���n>m����һ�ε���������������
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
