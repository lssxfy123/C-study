// Copyright 2017.刘珅珅
// author：刘珅珅
// 优先队列（堆）
#include <iostream>
#include <queue>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    priority_queue<float> q;
    q.push(66.6f);
    q.push(22.2f);
    q.push(44.4f);

    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << endl;
    q.pop();

    q.push(11.1f);
    q.push(55.5f);
    q.push(33.3f);

    while (!q.empty())
    {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << endl;
    return 0;
}
