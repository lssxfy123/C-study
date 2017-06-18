// Copyright 2017.���|�|
// author�����|�|
// ��ֵ�ļ���
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
