// Copyright 2017.���|�|
// author�����|�|
// C++11���õ��ӹ���
#include <iostream>
using namespace std;

void Test(int&& v)
{
}

template<typename T>
void Func(T&& formal_param)
{
    
}

int main(int argc, char* argv[])
{
    int a = 1;
    int&& r = 3;
    //Test(a);  // error����ֵ�����޷��󶨵���ֵ
    //Test(r);  // error����ֵ�����޷��󶨵���ֵ

    // ok������ģ����βΣ���ֵ���ÿ��԰󶨵���ֵ
    Func(a);  
    return 0;
}
