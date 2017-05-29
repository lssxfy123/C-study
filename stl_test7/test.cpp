// Copyright 2017.���|�|
// author�����|�|
// C++11���õ��ӹ���
#include <iostream>
using namespace std;

void Test(int&& v)
{
}

bool IsRightReference(int&& r)
{
    cout << "��ֵ" << endl;
    return true;
}

bool IsRightReference(int& l)
{
    cout << "��ֵ" << endl;
    return false;
}

template<typename T>
void FuncRule1(T& formal_param)
{
    T formal_param1 = 0;
    cout << "��֤����1" << endl;
}

// �β���Ҫ��const
// ���յ�ʵ��Ϊ��ֵ
template<typename T>
void FuncRule2(const T& formal_param)
{
    T formal_param1 = 0;
    cout << "��֤����2" << endl;
}

template<typename T>
void FuncRule3(T&& formal_param)
{
    int n = 0;
    T formal_param1 = n;
    cout << "��֤����3" << endl;
}

template<typename T>
void FuncRule4(T&& formal_param)
{
    int n = 0;
    T formal_param1 = n;
    cout << "��֤����4" << endl;
}

int main(int argc, char* argv[])
{
    int a = 1;
    int&& r = 3;
    //Test(a);  // error����ֵ�����޷��󶨵���ֵ
    //Test(r);  // error����ֵ�����޷��󶨵���ֵ

    // ���õ��ӹ���
    int actual_param1 = 1;
    int& actual_param2 = actual_param1;
    int&& actual_param3 = move(actual_param1);
    FuncRule1(actual_param2);
    IsRightReference(actual_param3);  // ��ֵ
    IsRightReference(forward<int>(actual_param3));  // ��ֵ

    // �ں���ģ���У����԰���ֵ�󶨵���ֵ
    FuncRule2(forward<int>(actual_param3));

    FuncRule3(actual_param2);
    FuncRule4(forward<int>(actual_param3));
    return 0;
}
