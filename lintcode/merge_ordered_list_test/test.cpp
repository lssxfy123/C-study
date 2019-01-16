// Copyright 2018.刘珅珅
// author：刘珅珅
// 合并两个排序链表
#include <iostream>
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

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
	// write your code here
	if (l1 == nullptr)
	{
		return l2;
	}

	if (l2 == nullptr)
	{
		return l1;
	}

	ListNode* head = nullptr;
	ListNode* p1 = nullptr;
	ListNode* p2 = nullptr;
	if (l1->val < l2->val)
	{
		head = l1;
		p1 = l1->next;
		p2 = l2;
	}
	else
	{
		head = l2;
		p1 = l2->next;
		p2 = l1;
	}

	ListNode* current = head;
	//在两个链表中遍历比较，将值较小的结点链接到current结点后
	while (p1 != nullptr && p2 != nullptr)
	{
		if (p1->val <= p2->val)
		{
			current->next = p1;
			current = p1;
			p1 = p1->next;
		}
		else
		{
			current->next = p2;
			current = p2;
			p2 = p2->next;
		}
	}

	if (p1 != nullptr)
	{
		current->next = p1;
	}

	if (p2 != nullptr)
	{
		current->next = p2;
	}

	return head;
}

int main(int argc, char* argv[])
{
	return 0;
}
