// Copyright 2018.刘珅珅
// author：刘珅珅
// sqrt
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

int sqrt(int x) {
    // write your code here
    if (x <= 0)
    {
        return 0;
    }

    if (x <= 2)
    {
        return 1;
    }

    int low = 1;
    int high = x / 2;
    int middle = 0;
    while (low <= high)
    {
        middle = (low + high) / 2;
        int divide = x / middle;  // 不能使用middle * middle，有可能会溢出
        if (divide == middle)
        {
            return middle;
        }

        // middle * middle < x
        if (divide > middle)
        {
            int divide_1 = x / (middle + 1);
            if (divide_1 <= (middle + 1))  // (middle + 1) * (middle + 1) >= x
            {
                return divide_1 == (middle + 1) ? middle + 1 : middle;
            }
            else
            {
                low = middle + 1;
            }
        }

        // middle * middle > x
        if (divide < middle )
        {
            int divide_2 = x / (middle - 1);
            if (divide_2 >= (middle - 1))  // (middle - 1) * (middle - 1) <= x
            {
                return middle - 1;
            }
            else
            {
                high = middle - 1;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    cout << sqrt(1) << endl;
    cout << sqrt(2) << endl;
    cout << sqrt(3) << endl;
    cout << sqrt(4) << endl;
    cout << sqrt(5) << endl;
    cout << sqrt(10) << endl;
    cout << sqrt(999999999) << endl;
    return 0;
}
