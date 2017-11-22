// Copyright 2017.刘珅珅
// author：刘珅珅
// 小数转换为二进制：大于0小于1的小数转换为二进制
#include <iostream>
using std::cout;
using std::endl;

void DecimalConvertBinary(double decimal);

int main(int argc, char* argv[])
{
    DecimalConvertBinary(0.34);
    cout << endl;
    return 0;
}

void DecimalConvertBinary(double decimal)
{
    int count = 53;

    while ((decimal != 0) && (count != 0))
    {
        decimal = decimal * 2;

        if (decimal >= 1)
        {
            cout << 1;
            decimal = decimal - 1;
        }
        else
        {
            cout << 0;
        }

        --count;
    }
}
