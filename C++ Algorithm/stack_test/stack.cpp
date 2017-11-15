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

// 栈是否为空
bool Stack::IsEmpty()
{
    if (top_ptr_ == NULL)
    {
        return true;
    }

    return false;
}

// 入栈
void Stack::Push(int element)
{
    Node* p = new Node;

    if (p == NULL)
    {
        exit(1);
    }

    p->element = element;
    p->next = top_ptr_;  // top_ptr_存储的是上一个栈元素
    top_ptr_ = p;  // 将top_ptr指向当前栈元素
    ++size_;
}


// 出栈，返回弹出栈的节点的元素值
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
