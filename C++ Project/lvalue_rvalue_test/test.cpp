// Copyright 2017.刘珅珅
// author：刘珅珅
// 左值和右值
#include <iostream>
using namespace std;

int main(int argc, char* argv)
{
    // a是左值
    // 3是右值
    int a = 3;

    // a++为先使用a的值，然后将a加1
    // a++产生的是一个临时对象
    //cout << &(a++) << endl;  // error, a++为右值
    cout << &(++a) << endl;
    //a++ = 3;
    return 0;
}
