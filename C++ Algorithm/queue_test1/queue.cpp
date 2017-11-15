#include "queue.h"

#include <iostream>
using std::cout;
using std::endl;

Queue::Queue()
{
    front_ptr_ = NULL;
    rear_ptr_ = NULL;
    size_ = 0;
}

Queue::~Queue()
{
    ClearQueue();
}

// 入队
void Queue::EnQueue(int element)
{
    Node* p = new Node;
    if (p == NULL)
    {
        exit(1);
    }

    p->element = element;
    p->next = NULL;
    // p->next = rear_ptr_;

    if (rear_ptr_ == NULL)
    {
        front_ptr_ = p;
        rear_ptr_ = p;
    }
    else
    {
        // 把上一个节点的next指针指向下一个节点
        // 这与栈正好相反，入栈时，是把下个节点的next指针指向上一个节点
        rear_ptr_->next = p;
        rear_ptr_ = p;
    }
    ++size_;
}

int Queue::DeQueue(bool& ok)
{
    if (size_ == 0)
    {
        ok = false;
        return 0;
    }

    Node* p = front_ptr_->next;
    int element = front_ptr_->element;
    delete front_ptr_;
    front_ptr_ = p;
    --size_;

    // 删除了最后一个节点后，让rear_ptr指向front_ptr
    if (size_ == 0)
    {
        rear_ptr_ = front_ptr_;
    }

    // cout << "size = " << size_ << endl;
    return element;
}

bool Queue::IsEmpty()
{
    if (front_ptr_ == NULL)
    {
        cout << "栈为空" << endl;
        return true;
    }

    return false;
}

void Queue::ClearQueue()
{
    while (front_ptr_ != NULL)
    {
        Node* p = front_ptr_->next;
        delete front_ptr_;
        front_ptr_ = p;
    }
}

