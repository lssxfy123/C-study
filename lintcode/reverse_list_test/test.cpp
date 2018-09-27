// Copyright 2018.���|�|
// author�����|�|
// ��ת����
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

class ListNode
{
public:
    ListNode(int value)
    {
        value_ = value;
        next_ = nullptr;
    }

public:
    int value_;
    ListNode* next_;
};

ListNode* reverse(ListNode* head)
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = head->next_;
    ListNode* p3 = nullptr;

    for (;p2 != nullptr;)
    {
        p3 = p2->next_;
        p2->next_ = p1;
        p1 = p2;
        p2 = p3;
    }

    head->next_ = nullptr;
    head = p1;
    return head;
}

// ���õķ���
ListNode* reverse1(ListNode* head)
{
    ListNode* prev = nullptr;
    while (head != nullptr)
    {
        ListNode* tmp = head->next_;
        head->next_ = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}

int main(int argc, char* argv[])
{
    return 0;
}
