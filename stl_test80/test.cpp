// Copyright 2017.���|�|
// author�����|�|
// ����
#include <iostream>
#include <queue>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    queue<string> q;
    q.push("These ");
    q.push("are ");
    q.push("more than ");

    cout << q.front();
    q.pop();
    cout << q.front();
    q.pop();

    q.push("four ");
    q.push("words!");

    // �������һ��Ԫ��
    cout << q.back();
    cout << endl;
    return 0;
}
