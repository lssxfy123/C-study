// Copyright 2017.���|�|
// author�����|�|
// ����������
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Ԫ��5���ڵ�λ��
    vector<int>::const_iterator pos = find(coll.cbegin(), coll.cend(), 5);
    cout << "pos:   " << *pos << endl;

    // ���������
    vector<int>::const_reverse_iterator rpos(pos);
    cout << "rpos:   " << *rpos << endl;

    cout << *coll.rbegin() << endl; // 9
    // �ڴ����
    //cout << *coll.rend() << endl;
    return 0;
}
