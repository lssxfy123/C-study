// Copyright 2017.���|�|
// author�����|�|
// Lambda��Ϊ�㷨��ʵ��
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    deque<int> coll = { 1, 3, 19, 5, 13, 7, 11, 2, 17 };
    int x = 5;
    int y = 12;

    // Lambda���ʽ��Ϊ�㷨ʵ��
    // [=]��ֵ��ʽ
    auto pos = find_if(coll.cbegin(), coll.cend(), [=](int i) {return i > x && i < y; });

    if (pos != coll.end())
    {
        cout << "first elem > 5 and < 12: " << *pos << endl;
    }
    return 0;
}
