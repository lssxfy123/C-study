// Copyright 2017.刘珅珅
// author：刘珅珅
// 链表反序
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct ListNode
{
    int val;
    struct ListNode* next;
} ListNode;

ListNode* CreateList(ListNode* head);
void PrintList(ListNode* head);
ListNode* ReverseList(ListNode* head);

// 链表划分
ListNode* Partition(ListNode* head, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    // 第1个大于x的结点
    ListNode* first_greater_node = nullptr;
    ListNode* prev_first_greater_node = nullptr;
    ListNode* tmp = head;
    ListNode* prev = nullptr;
    bool hasHead = false;
    while (tmp != nullptr)
    {
        if (tmp->val >= x)
        {
            prev_first_greater_node = prev;
            first_greater_node = tmp;
            prev = tmp;
            tmp = tmp->next;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
        hasHead = true;  // 链表第1个结点小于x，head结点不需要更改
    }
    if (first_greater_node == nullptr || tmp == nullptr)
    {
        return head;
    }

    while (tmp != nullptr)
    {
        if (tmp->val >= x)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        else
        {
            ListNode* tmp_next = tmp->next;
            prev->next = tmp_next;
            if (prev_first_greater_node != nullptr)
            {
                prev_first_greater_node->next = tmp;
            }
            prev_first_greater_node = tmp;
            tmp->next = first_greater_node;
            if (!hasHead)
            {
                head = tmp;
                hasHead = true;
            }
            tmp = prev->next;
        }
    }

    return head;
}

void ListTest(ListNode* head);

int main(int argc, char* argv[])
{
    ListNode* head = NULL;

    head = CreateList(head);
    cout << "链表划分" << endl;
    head = Partition(head, 3);
    PrintList(head);
    cout << endl;
    ListTest(head);
    PrintList(head);
    cout << endl;

    cout << "链表反序" << endl;
    head = ReverseList(head);
    // ReverseList(head);  // 这样操作是不会将链表反序，因为在函数中修改指针本身是没有用的
    PrintList(head);
    cout << endl;

    return 0;
}

void ListTest(ListNode* head)
{
    head->val = 1;  // 会修改函数外部实参中的值
    head = NULL;  // 不会影响函数外部实参的值
}

// 创建链表
ListNode* CreateList(ListNode* head)
{
    ListNode* list1_ptr = NULL;
    ListNode* list2_ptr = NULL;

    list1_ptr = new ListNode;
    // list2_ptr = new List;

    memset(list1_ptr, 0, sizeof(ListNode));

    cin >> list1_ptr->val;

    // 如果每次新节点的元素number大于0，则增加节点
    // 初始化状态下head为NULL，第一次循环，head==NULL，将head
    // 指向节点list1_ptr，并将list2_ptr指向list1_ptr，这样list2_ptr
    // 与head指向同一个节点；第二次循环，将list2_ptr->next指向新产生
    // 的节点list1_ptr，这样相当于将head->next指向了新的list1_ptr，然后
    // 将list2_ptr指向list1_ptr；第三次循环，将list2_ptr->next指向新产生
    // 的节点list1_ptr，实际是将第二个节点的next指针指向了新产生的list1_ptr
    // 这样就构成了链表
    while (list1_ptr->val > 0)
    {
        if (head == NULL)
        {
            head = list1_ptr;
        }
        else
        {
            list2_ptr->next = list1_ptr;
        }

        list2_ptr = list1_ptr;

        list1_ptr = new ListNode;  // 将list1_ptr当成每次添加的新节点
        memset(list1_ptr, 0, sizeof(ListNode));
        cin >> list1_ptr->val;

        list1_ptr->next = NULL;
    }

    return head;
}

void PrintList(ListNode* head)
{
    if (head == NULL)
    {
        cout << "链表为空" << endl;
    }
    else
    {
        

        while (head != NULL)
        {
            cout << head->val << ",";

            // 在函数中修改指针本身，不会影响函数外部的实参指针
            head = head->next;
        }
    }

}

// 链表反序
ListNode* ReverseList(ListNode* head)
{
    if (head == NULL)
    {
        cout << "链表为空" << endl;
        return head;
    }

    ListNode* p1 = NULL;
    ListNode* p2 = NULL;
    ListNode* p3 = NULL;

    p1 = head;
    p2 = p1->next;

    // p1：指向原表中当前节点的上级节点
    // p2：指向原表中当前节点
    // p3：指向原表中当前节点的后继节点
    for (; p2 != NULL;)
    {
        // 将当前节点p2的下一个节点存储在p3中
        p3 = p2->next;

        // 将当前节点p2的原上级节点p1当成后继节点
        p2->next = p1;

        // 将p1指向当前节点
        p1 = p2;

        // 将p2指向原表中的下一节点
        p2 = p3;
    }

    // 原链表的新节点为反序后新链表的尾节点，所以head->next指向NULL
    head->next = NULL;

    // p1会最终指向原链表的尾节点，即新链表的头节点，所以将head指向p1
    head = p1;

    return head;
}
