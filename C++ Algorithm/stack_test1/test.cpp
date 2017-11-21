// Copyright 2017.刘珅珅
// author：刘珅珅
// 用两个队列实现栈

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
    stack.Push(4);

    bool ok;
    while (!stack.IsEmpty())
    {
        cout << stack.Pop(ok) << endl;
    }

    return 0;
}
