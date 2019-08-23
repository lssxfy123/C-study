// Copyright 2019.刘珅珅
// author：刘珅珅
// 删除链表中的第n到m个节点
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

ListNode * deleteNode(ListNode * head, int n, int m) {
    // Write your code here
    ListNode* tmp = head;
    ListNode* start = head;
    ListNode* end = nullptr;
    int index = 0;
    while (tmp != nullptr)
    {
        ++index;
        if (index == n)
        {
            start = tmp;
        }

        tmp = tmp->next;
        if (index == m)
        {
            end = tmp->next;
        }

    }

    if (n == 0)
    {
        head = end;
    }
    else
    {
        start->next = end;
    }

    return head;
}

int main(int argc, char* argv[])
{
    return 0;
}
