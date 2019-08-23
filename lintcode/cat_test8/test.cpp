// Copyright 2019.���|�|
// author�����|�|
// ������е�
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

    // ����ָ�뷨��quick=quick+2,slow=slow+1
    // ��quick���ʵ�����ĩβ����ǰһ��ֵʱ��slow���÷��ʵ��е�
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