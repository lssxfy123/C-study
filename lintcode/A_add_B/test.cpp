// Copyright 2018.���|�|
// author�����|�|
// A + B����
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

// ��������Ʋ���
string ToBinary(int x)
{
    string result;
    for (int i = 0; i < 32; ++i)
    {
        if ((x & (1 << (31 - i))) == 0)
        {
            result.append("0");
        }
        else
        {
            result.append("1");
        }

        if ((i + 1) % 4 == 0)
        {
            result.append(" ");
        }
    }
    return result;
}

int main(int argc, char* argv)
{
    int a = 2147483647;
    int b = 5;
    int c = a + b;
    cout << "use + result: " << c << endl;
    while (b != 0)
    {
        // λ�����^����λΪ1������0��1���
        int tmp_a = (a ^ b);

        // λ�����&����������Ϊ1��λ��ӵĽ��
        // ����1λ�����λ
        int tmp_b = (a & b) << 1;
        a = tmp_a;
        b = tmp_b;
    }
    cout << "use bit operator result: " << a << endl;
    return 0;
}
