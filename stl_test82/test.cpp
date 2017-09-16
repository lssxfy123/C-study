// Copyright 2017.���|�|
// author�����|�|
// bitset
#include <bitset>
#include <iostream>
#include <limits>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // numColors����ָ��ö�ٵ���Ч����
    enum Color {red, yellow, green, blue, white, black, orange, numColors} ;

    // bitset��ģ���ββ�������
    // ���ǲ��������ŵ�������
    // ָ�������ɵ�bit��
    // numColors = 7u
    bitset<numColors> useColors;
    useColors.set(red);
    useColors.set(blue);

    cout << "bitfield of used colors:   " << useColors << endl;
    cout << "number of used colors:  " << useColors.count() << endl;
    cout << "bitfield of unused colors:  " << ~useColors << endl;
    cout << endl;

    // ����ֵ��bit����֮���ת��
    cout << "267 as binary short:   "
        << bitset<numeric_limits<unsigned short>::digits>(267)
        << endl;

    cout << "267 as binary long:  "
        << bitset<numeric_limits<unsigned long>::digits>(267)
        << endl;

    cout << "10,000,000 with 24 bits:   "
        << bitset<24>(10000000) << endl;

    cout << "12, 345, 678 with 42 bits: "
        << bitset<42>(12345678).to_string() << endl;

    cout << "\"10001010011\" as number:    "
        << bitset<100>("1000101011").to_ullong() << endl;
    return 0;
}
