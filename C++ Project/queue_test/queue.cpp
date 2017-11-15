#include "queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{

}

void Queue::EnQueue(int element)
{
    en_stack_.Push(element);
}

int Queue::DeQueue(bool& ok)
{
    if (!de_stack_.IsEmpty())
    {
        return de_stack_.Pop(ok);
    }
    else
    {
        if (en_stack_.IsEmpty())
        {
            ok = false;
            return 0;
        }

        int en_size = en_stack_.Size();

        // ��ջen_stack_������Ԫ��ѹ�˵�
        // ջde_stack_��
        for (int i = 0; i != en_size; ++i)
        {
            de_stack_.Push(en_stack_.Pop(ok));
        }
    }

    return de_stack_.Pop(ok);
}

bool Queue::IsEmpty()
{
    if (en_stack_.IsEmpty() && de_stack_.IsEmpty())
    {
        return true;
    }

    return false;
}
