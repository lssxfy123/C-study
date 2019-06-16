// Copyright 2019.���|�|
// author�����|�|
// ��ת����II
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

class ListNode
{
public:
    ListNode(int value)
    {
        val = value;
        next = nullptr;
    }

public:
    int val;
    ListNode* next;
};

ListNode * reverseBetween(ListNode * head, int m, int n) {
    // write your code here
    if (head == nullptr || n == 1)
    {
        return head;
    }

    ListNode* begin = head;
    ListNode* prev = nullptr;

    // �ҵ���m�����begin����ǰһ�����prev
    while (m > 1)
    {
        prev = begin;
        begin = begin->next;
        --m;
    }

    if (begin == nullptr || begin->next == nullptr)
    {
        return head;
    }

    // �ҵ���n�����end
    ListNode* end = head;
    while (n > 1)
    {
        end = end->next;
        --n;
    }

    // ��¼end����һ�����next
    ListNode* next = end->next;

    // �ڷ�ת��������ʱ��p=nullptr���������һ��������һ�����
    // �ڷ�ת��������ʱ��next������end������һ���
    ListNode* p = next;
    while (begin != next)
    {
        ListNode* tmp = begin->next;
        begin->next = p;
        p = begin;
        begin = tmp;
    }

    if (prev == nullptr)  // ��ʾ�ӵ�һ����㿪ʼ��ת
    {
        head = p;
    }
    else
    {
        prev->next = p;
    }
    return head;
}

int main(int argc, char* argv[])
{
    return 0;
}
