// Copyright 2017.���|�|
// author�����|�|
// function adapter���Զ����function object
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "../include/fopow.hpp"
using namespace std;
using namespace std::placeholders;

int main(int argc, char* argv[])
{
    vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // ��coll�е�Ԫ����Ϊ�ݣ�����Ϊ3
    transform(coll.begin(), coll.end(),  // source
        ostream_iterator<float>(cout, " "),   // destination
        bind(fopow<float, int>(), 3, _1));  // operation
    cout << endl;

    // ��3���ݣ�����Ϊcoll��Ԫ��
    transform(coll.begin(), coll.end(),
        ostream_iterator<float>(cout, " "),
        bind(fopow<float, int>(), _1, 3));
    cout << endl;
    return 0;
}
