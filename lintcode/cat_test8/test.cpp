// Copyright 2019.刘珅珅
// author：刘珅珅
// 链表的中点
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode * middleNode(ListNode * head) {
    // write your code here
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* quick = head;
    ListNode* slow = head;

    // 快慢指针法：quick=quick+2,slow=slow+1
    // 当quick访问到链表末尾或其前一个值时，slow正好访问到中点
    while (quick->next != nullptr && quick->next->next != nullptr)
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(int argc, char* argv[])
{
    return 0;
}