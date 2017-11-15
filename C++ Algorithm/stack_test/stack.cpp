#include "stack.h"
#include <iostream>

Stack::Stack()
{
    top_ptr_ = NULL;
    size_ = 0;
}

Stack::~Stack()
{
    ClearStack();
}

// ջ�Ƿ�Ϊ��
bool Stack::IsEmpty()
{
    if (top_ptr_ == NULL)
    {
        return true;
    }

    return false;
}

// ��ջ
void Stack::Push(int element)
{
    Node* p = new Node;

    if (p == NULL)
    {
        exit(1);
    }

    p->element = element;
    p->next = top_ptr_;  // top_ptr_�洢������һ��ջԪ��
    top_ptr_ = p;  // ��top_ptrָ��ǰջԪ��
    ++size_;
}


// ��ջ�����ص���ջ�Ľڵ��Ԫ��ֵ
int Stack::Pop(bool& ok)
{
    if (size_ == 0)
    {
        ok = false;
        return 0;
    }

    Node* p = NULL;
    int element = 0;
    element = top_ptr_->element;
    p = top_ptr_->next;
    delete top_ptr_;
    top_ptr_ = p;
    --size_;
    return element;
}

int Stack::Size() const
{
    return size_;
}

void Stack::ClearStack()
{
    Node* p = NULL;

    while (top_ptr_ != NULL)
    {
        p = top_ptr_->next;
        delete top_ptr_;
        top_ptr_ = p;
    }

    size_ = 0;
}
