// Copyright 2017.刘珅珅
// author：刘珅珅
// 用两个栈实现队列
// 核心思想是：入队直接压人栈en_stack_
// 出队，判断栈de_stack_是否为空，如果不
// 为空，则直接弹出de_stack_的栈顶元素
// 如果为空，则将栈en_stack_的所有元素
// 压入栈de_stack_中，然后弹出栈de_stack_
// 的栈顶元素

#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Queue queue;
    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);

    bool ok = false;

    while (!queue.IsEmpty())
    {
        cout << queue.DeQueue(ok) << endl;
    }

    return 0;
}
