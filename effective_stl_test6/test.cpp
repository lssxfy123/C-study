// Copyright 2017.���|�|
// author�����|�|
// ���vector��string���������
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vec;
    vec.reserve(10);
    vec.push_back(1);
    vec.push_back(2);
    cout << "capacity size = " << vec.capacity() << endl;

    // ͨ��swap��������������
    // ����һ����ʱ��vector������vec
    // ����ʱֻ��Ϊ��������Ԫ�ط����ڴ�
    // ���������ʱ��vectorû�ж���Ŀռ�
    vector<int>(vec).swap(vec);
    cout << "capacity size = " << vec.capacity() << endl;

    // ���vector
    vector<int>().swap(vec);
    return 0;
}
