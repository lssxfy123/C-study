// Copyright 2017.���|�|
// author�����|�|
// C++�еĺ���������
#include <iostream>
using namespace std;

int number = 1;
static int value = 2;

int main(int argc, char* argv[])
{
    extern int a;
    a = 1;  // ����extern��չ����error
    number = 0;
    value = 9;

    return 0;
}

int a = 0;

