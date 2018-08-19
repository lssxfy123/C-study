// Copyright 2018.刘珅珅
// author：刘珅珅
// A + B问题
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

// 输出二进制补码
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
        // 位运算符^相异位为1，代表0与1相加
        int tmp_a = (a ^ b);

        // 位运算符&代表两个都为1的位相加的结果
        // 左移1位代表进位
        int tmp_b = (a & b) << 1;
        a = tmp_a;
        b = tmp_b;
    }
    cout << "use bit operator result: " << a << endl;
    return 0;
}
