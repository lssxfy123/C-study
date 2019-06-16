// Copyright 2019.刘珅珅
// author：刘珅珅
// 翻转链表II
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

    // 找到第m个结点begin和其前一个结点prev
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

    // 找到第n个结点end
    ListNode* end = head;
    while (n > 1)
    {
        end = end->next;
        --n;
    }

    // 记录end的下一个结点next
    ListNode* next = end->next;

    // 在翻转整个链表时，p=nullptr，代表最后一个结点的下一个结点
    // 在翻转部分链表时，next结点就是end结点的下一结点
    ListNode* p = next;
    while (begin != next)
    {
        ListNode* tmp = begin->next;
        begin->next = p;
        p = begin;
        begin = tmp;
    }

    if (prev == nullptr)  // 表示从第一个结点开始翻转
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
