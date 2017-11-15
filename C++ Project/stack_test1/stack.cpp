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

// ��ջʱ���ĸ����в�Ϊ�վͽ����ĸ�����
// ����������ж�Ϊ�գ�������q1����
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

// ��ջ������Ϊ�յĶ����е�Ԫ������һ��������Ķ�ת�Ƶ���һ��������
// Ȼ�����µ��Ǹ�Ԫ�س�����
int Stack::Pop(bool& ok)
{
    int element;
    if (q1_.IsEmpty() && q2_.IsEmpty())
    {
        ok = false;
        return 0;
    }

    if (q2_.IsEmpty())  // q2_Ϊ�գ�q1_��Ϊ��
    {
        // q1_������ֻ��һ��Ԫ�أ�������q2_����
        while (!(q1_.Size() == 1))
        {
            q2_.EnQueue(q1_.DeQueue(ok));
        }

        element = q1_.DeQueue(ok);

        //cout << "q1.size = " << q1_.Size() << endl;
        //cout << "q2.size = " << q2_.Size() << endl;
    }
    else // q2_��Ϊ�գ�q1_�϶�Ϊ��
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
