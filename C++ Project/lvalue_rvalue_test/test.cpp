// Copyright 2017.���|�|
// author�����|�|
// ��ֵ����ֵ
#include <iostream>
using namespace std;

int main(int argc, char* argv)
{
    // a����ֵ
    // 3����ֵ
    int a = 3;

    // a++Ϊ��ʹ��a��ֵ��Ȼ��a��1
    // a++��������һ����ʱ����
    //cout << &(a++) << endl;  // error, a++Ϊ��ֵ
    cout << &(++a) << endl;
    //a++ = 3;
    return 0;
}
