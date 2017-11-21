// Copyright 2017.���|�|
// author�����|�|
// ������ջʵ�ֶ���
// ����˼���ǣ����ֱ��ѹ��ջen_stack_
// ���ӣ��ж�ջde_stack_�Ƿ�Ϊ�գ������
// Ϊ�գ���ֱ�ӵ���de_stack_��ջ��Ԫ��
// ���Ϊ�գ���ջen_stack_������Ԫ��
// ѹ��ջde_stack_�У�Ȼ�󵯳�ջde_stack_
// ��ջ��Ԫ��

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
