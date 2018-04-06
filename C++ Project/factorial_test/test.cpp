// Copyright 2018.���|�|
// author�����|�|
// �׳˼��㣺 10000����
#include <assert.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef int Type;
typedef vector<Type> BigInt;
const Type Mod = 10000;
const double PI = 3.1415926;
const double E = 2.718281828459;

// ��10000���ڵĽ׳�
// ����10000�п��ܻ���ִ���
BigInt Factorial(Type n)
{
    assert(n >= 0 && n <= 10000);
    int factorial_length = 0.5 * log10(2 * n * PI) + n * log10(n / E) + 1;
    cout << "factorial_length = " << factorial_length << endl;
    BigInt result;
    result.reserve(factorial_length);
    result.push_back(1);
    for (Type factor = 1; factor <= n; ++factor)
    {
        Type carry = 0;
        for (auto& item : result)
        {
            // ����Ƽ���
            // ����ǳ���10000�Ľ׳�
            // product�п���>10000 * 10000
            // �Ӷ�����carry����10000
            Type product = item * factor + carry;
            item = product % Mod;
            carry = product / Mod;
        }

        // ���carry����0��˵�����
        // ������result���еĳ���
        if (carry > 0)
        {
            result.push_back(carry);
        }
    }
    return result;
}

// ��������ƽ׳�
// �������㷨֮�����ڳ���10000��
// ���ִ��������ڼ���carryʱ��
// ���ֳ���10000��ֵ���Ӷ���������
// ��������ʵ���岻��������㳬��
// 10000�Ľ׳ˣ���ȫ����ʹ��ʮ����ƣ�
// ������Ƶ�
BigInt FactorialModify(Type n)
{
    int factorial_length = 0.5 * log10(2 * n * PI) + n * log10(n / E) + 1;
    BigInt result;
    result.reserve(factorial_length);
    result.push_back(1);
    for (Type factor = 1; factor <= n; ++factor)
    {
        Type carry = 0;
        for (auto& item : result)
        {
            // ����Ƽ���
            Type product = item * factor + carry;
            item = product % Mod;
            carry = product / Mod;
        }

        // ���carry����0��˵�����
        // ������result���еĳ���
        if (carry > 0)
        {
            // ����
            while (carry >= Mod)
            {
                result.push_back(carry % Mod);
                carry = carry / Mod;
            }

            if (carry > 0)
            {
                result.push_back(carry);
            }
        }
    }
    return result;
}

void PrintBigInt(const BigInt& number)
{
    if (number.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        int mod_length = to_string(Mod).size();
        string format = "%0" + to_string(mod_length - 1) + "d";
        // ���λ��ʵ�����
        printf("%d", number.back());
        for (auto itor = number.rbegin() + 1; itor != number.rend(); ++itor)
        {
            // ��ָ��λ��������������λ��0
            printf(format.c_str(), *itor);
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    BigInt result = Factorial(10000);
    PrintBigInt(result);
    return 0;
}
