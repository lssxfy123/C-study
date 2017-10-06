// Copyright 2017.���|�|
// author�����|�|
// constexpr����
#include <iostream>
#include "../include/print.hpp"
using namespace std;

constexpr int new_size() { return 42; }

// ����ֵ��һ���ǳ������ʽ
constexpr int scale(int count)
{
    return new_size() * count;
}

int main(int argc, char* argv[])
{
    constexpr int foo = new_size();

    // ok��scale(2)�ķ���ֵΪ�������ʽ
    int arr[scale(2)];
    int i = 2;

    // error��scale(i)���ǳ������ʽ
    // int arr1[scale(i)];
    int k = scale(i);  // ok
    return 0;
}
