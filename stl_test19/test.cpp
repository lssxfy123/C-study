// Copyright 2017.刘珅珅
// author：刘珅珅
// 数值的极限
#include <iostream>
#include <limits>
using namespace std;

int main(int argc, char* argv[])
{
    cout << boolalpha;
    cout << "max(short): " << numeric_limits<short>::max() << endl;
    cout << "min(short): " << numeric_limits<short>::min() << endl;
    cout << "is signed(short): " << numeric_limits<short>::is_signed << endl;
    cout << "is specialized(short): " << numeric_limits<short>::is_specialized << endl;
    return 0;
}
