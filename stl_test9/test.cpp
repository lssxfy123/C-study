// Copyright 2017.���|�|
// author�����|�|
// C++11 move����
#include <iostream>
using namespace std;

void Fun(int& x)
{
    cout << "lvalue ref" << endl;
}

void Fun(int&& x)
{
    cout << "rvalue ref" << endl;
}

void Fun(const int& x)
{
    cout << "const lvalue ref" << endl;
}

void Fun(const int&& x)
{
    cout << "const rvalue ref" << endl;
}

// ����ת������ģ��
template <typename T>
void PerfectForward(T&& t)
{
    Fun(forward<T>(t));
}

int main(int argc, char* argv[])
{
    PerfectForward(10);

    int a = 5;
    PerfectForward(a);
    PerfectForward(move(a));

    const int b = 8;
    PerfectForward(b);
    PerfectForward(move(b));
    return 0;
}
