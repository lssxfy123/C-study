// Copyright 2015.���|�|
// author�����|�|
// C++ʵ��һ����ʽջ

#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
    Stack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    bool ok;

    int size = stack.Size();
    for (int i = 0; i != size; ++i)
    {
        cout << stack.Pop(ok) << endl;
    }

    if (stack.IsEmpty())
    {
        cout << "ջΪ��" << endl;
    }
    else
    {
        cout << "ջ��Ϊ��" << endl;
    }
    return 0;
}
