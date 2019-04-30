// Copyright 2018.���|�|
// author�����|�|
// ɾ�������������ظ�Ԫ��
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
		// next����ɾ�����ȴ洢next->next
		// ��ǰ���prev��nextָ��ָ��next->next
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
