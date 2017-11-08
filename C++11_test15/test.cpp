// Copyright 2017.���|�|
// author�����|�|
// ת��
#include <iostream>
#include "../include/print.hpp"
using namespace std;

// ����ת��
// ��������ת��
// ��һ��ģ���β�FΪ�ɵ��ñ��ʽ
// T1��T2Ϊ���������β�
template<typename F, typename T1, typename T2>
void Flip1(F f, T1 t1, T2 t2)
{
    f(t1, t2);
}

// ����һ����ת��
template<typename F, typename T1, typename T2>
void Flip2(F f, T1&& t1, T2&& t2)
{
    f(t1, t2);
}

// ʹ��std::forwardʵ������ת��
template<typename F, typename T1, typename T2>
void Flip3(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

void F(int v1, int& v2)
{
    ++v2;
}

void G(int& i, int&& j)
{
    
}

int main(int argc, char* argv[])
{
    // ת�������������
    cout << "ת��������" << endl;
    int i1 = 0;
    int j1 = 1;
    cout << "ת��" << endl;
    Flip1(F, i1, j1);
    cout << "i = " << i1 << " j = " << j1 << endl;

    cout << "ֱ�ӵ���" << endl;
    int i2 = 0;
    int j2 = 1;
    F(i2, j2);
    cout << "i = " << i2 << " j = " << j2 << endl;
    cout << endl;

    cout << "����һ��ת��" << endl;
    int i3 = 0;
    int j3 = 1;
    Flip2(F, i3, j3);
    cout << "i = " << i3 << " j = " << j3 << endl;

    //Flip2(G, i3, 4);  // error

    cout << "����ת��" << endl;
    int i4 = 0;
    int j4 = 1;
    Flip3(F, i4, j4);
    cout << "i = " << i4 << " j = " << j4 << endl;
    Flip3(G, i4, 8);

    return 0;
}
