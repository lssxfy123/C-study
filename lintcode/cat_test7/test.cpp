// Copyright 2019.刘珅珅
// author：刘珅珅
// 在排序链表中插入一个节点
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

ListNode * insertNode(ListNode * head, int val) {
    // write your code here
    ListNode* tmp = head;
    ListNode* prev = nullptr;
    while (tmp != nullptr && tmp->val < val)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    ListNode* node = new ListNode(val);
    if (prev != nullptr)
    {
        node->next = tmp;
        prev->next = node;
    }
    else
    {
        node->next = head;
        head = node;
    }

    return head;

}

int main(int argc, char* argv[])
{
	return 0;
}
