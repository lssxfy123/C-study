// Copyright 2015.刘珅珅
// author：刘珅珅
// C++实现一个链式栈

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
        cout << "栈为空" << endl;
    }
    else
    {
        cout << "栈不为空" << endl;
    }
    return 0;
}
