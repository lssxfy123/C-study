// Copyright 2017.���|�|
// author�����|�|
// set��map�����ıȽ�������Եȼ�ֵ��׼��
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // ���������
    set<int, less_equal<int>> set1;
    set1.insert(10);

    // error���׳��쳣���ȽϺ����ڵ�ֵ����·���true
    // set1.insert(10);

    map<int, int, less_equal<int>> map1;
    map1.insert({1, 2});

    // error���׳��쳣
    //map1.insert(make_pair(1, 3));

    return 0;
}
