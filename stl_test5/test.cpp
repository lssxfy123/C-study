// Copyright 2017.���|�|
// author�����|�|
// ��ֵ����
#include <iostream>
using namespace std;

//bool isRValue(int&& r)
//{
//    cout << "��ֵ" << endl;
//    return true;
//}
//
//bool isRValue(int& l)
//{
//    cout << "��ֵ" << endl;
//    return false;
//}

int main(int argc, char* argv[])
{
    int a = 5;
    const int b = 6;
    int c = 7;

    // �ǳ�����ֵ���ÿ��԰󶨵��ǳ�����ֵ
    int&& r1 = 4;  // �ǳ�����ֵ
    r1 = 5;  // ��������д���룬��û������
    //int&& r2 = a;  // error����ֵ���ò��ܰ󶨵���ֵ
    int&& r3 = a + c;  // ��ʱ���󣬷ǳ�����ֵ

    // ������ֵ���ÿ��԰󶨵��ǳ�����ֵ�ͳ�����ֵ
    // ������ֵ���ñ���û����ʵ����
    const int&& r4 = 5;
    const int&& r5 = a + b;  // ������ֵ
    //const int&& r6 = a;  // error�����ܰ󶨵���ֵ

    // ע�⣺�󶨵���ֵ����ֵ���ñ�����һ����ֵ
    // ��Ϊ��������
    //int&& r7 = r1;  // error�����ܰ󶨵���ֵ
    int&& r8 = move(r1);  // ok��ͨ��move����ֵ�����ֵ
    return 0;
}
