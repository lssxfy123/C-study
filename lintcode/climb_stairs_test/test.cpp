// Copyright 2018.���|�|
// author�����|�|
// ��¥��
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// �ݹ�ķ�ʽ̫������VS��n = 44�ܼ�������
// ��lintcode��û�ܼ�������
int climbStairs(int n) {
    // write your code here
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairs1(int n) {
    // write your code here
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    queue<int> tmp;
    tmp.push(1);
    tmp.push(2);
    for (int i = 3; i <= n; ++i)
    {
        tmp.push(tmp.front() + tmp.back());
        tmp.pop();
    }
    return tmp.back();
}

int climbStairs2(int n) {
    // write your code here
    if (n <= 2)
    {
        return n;
    }

    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    for (int i = 2; i < n; ++i)
    {
        tmp.push_back(tmp[i - 1] + tmp[i - 2]);
    }
    return tmp.back();
}

int main(int argc, char* argv[])
{
    cout << climbStairs1(44) << endl;
    cout << climbStairs2(44) << endl;
    return 0;
}
