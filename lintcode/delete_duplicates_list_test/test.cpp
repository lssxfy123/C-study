// Copyright 2018.刘珅珅
// author：刘珅珅
// 删除排序链表中重复元素
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

ListNode* deleteDuplicates(ListNode* head) {
    // write your code here
    if (head == nullptr)
    {
        return head;
    }

    ListNode* prev = head;
    ListNode* next = head->next;
    ListNode* tmp = nullptr;
    while (next != nullptr)
    {
		// next结点的删除：先存储next->next
		// 将前结点prev的next指针指向next->next
        if (next->val == prev->val)
        {
            tmp = next->next;
            prev->next = tmp;
            delete next;
            next = tmp;
        }
        else
        {
            prev = next;
            next = next->next;
        }
    }
    return head;
}

int main(int argc, char* argv[])
{
    return 0;
}
