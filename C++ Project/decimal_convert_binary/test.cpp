// Copyright 2017.���|�|
// author�����|�|
// С��ת��Ϊ�����ƣ�����0С��1��С��ת��Ϊ������
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
