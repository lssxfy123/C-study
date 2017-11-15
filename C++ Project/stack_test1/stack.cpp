#include "stack.h"

#include <iostream>
using std::cout;
using std::endl;

Stack::Stack()
{

}

Stack::~Stack()
{

}

bool Stack::IsEmpty()
{
    if (q1_.IsEmpty() && q2_.IsEmpty())
    {
        return true;
    }

    return false;
}

// 入栈时，哪个队列不为空就进入哪个队列
// 如果两个队列都为空，进进入q1队列
void Stack::Push(int element)
{
    if (q1_.IsEmpty() && q2_.IsEmpty())
    {
        q1_.EnQueue(element);
    }
    else if (!q1_.IsEmpty())
    {
        q1_.EnQueue(element);
    }
    else if (!q2_.IsEmpty())
    {
        q2_.EnQueue(element);
    }
}

// 出栈：将不为空的队列中的元素留下一个，其余的都转移到另一个队列中
// 然后将留下的那个元素出队列
int Stack::Pop(bool& ok)
{
    int element;
    if (q1_.IsEmpty() && q2_.IsEmpty())
    {
        ok = false;
        return 0;
    }

    if (q2_.IsEmpty())  // q2_为空，q1_不为空
    {
        // q1_队列中只留一个元素，其余入q2_队列
        while (!(q1_.Size() == 1))
        {
            q2_.EnQueue(q1_.DeQueue(ok));
        }

        element = q1_.DeQueue(ok);

        //cout << "q1.size = " << q1_.Size() << endl;
        //cout << "q2.size = " << q2_.Size() << endl;
    }
    else // q2_不为空，q1_肯定为空
    {
        while (!(q2_.Size() == 1))
        {
            q1_.EnQueue(q2_.DeQueue(ok));
        }

        element = q2_.DeQueue(ok);

        //cout << "q1.size = " << q1_.Size() << endl;
        //cout << "q2.size = " << q2_.Size() << endl;
    }

    return element;
}
