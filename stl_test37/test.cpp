// Copyright 2017.���|�|
// author�����|�|
// ������Ϊ�㷨��ʵ��2�������ж�ʽ
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// �ж��Ƿ�Ϊ����
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

    // ���ҵ�1������
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
