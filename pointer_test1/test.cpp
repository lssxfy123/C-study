// Copyright 2017.���|�|
// author�����|�|
// ָ��Ĳ���
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int n = 2;
    int* n_ptr = &n;

    cout << n_ptr << endl;  // 0116FA00
    cout << &n << endl;  // 0116fa00
    ++n_ptr;
    cout << n_ptr << endl;  // 0116FA04

    --n_ptr;
    cout << n_ptr << endl;  // 0116FA00

    int m = 5;
    int* m_ptr = &m;

    cout << m_ptr << endl;  // 0116F9E8

    int k = m_ptr - n_ptr;

    // kΪ������ַ֮���(��ֵ) / (���͵��ֽڴ�С)
    cout << k << endl;  // -6

    // error��ָ�벻���븡����+��-
    // m_ptr = m_ptr + 9.2;

    // error��ָ�벻�����
    // int x = m_ptr + n_ptr;

    void* v_ptr = &m;
    //++v_ptr;  // error��voidָ�벻�ܽ�����������
    return 0;
}
