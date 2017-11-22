// Copyright 2017.刘珅珅
// author：刘珅珅
// 链表反序
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef struct List
{
    int number;
    struct List* next;
} List;

List* CreateList(List* head);
void PrintList(List* head);
List* ReverseList(List* head);
int findNode(List*head, unsigned int k);

int main(int argc, char* argv[])
{
    List* head = NULL;

    head = CreateList(head);
    PrintList(head);

    int value = findNode(head, 2);
    cout << "value = " << value << endl;

    cout << "链表反序" << endl;
    head = ReverseList(head);
    PrintList(head);

    return 0;
}

// 创建链表
List* CreateList(List* head)
{
    List* list1_ptr = NULL;
    List* list2_ptr = NULL;  // 相当一个temp节点

    list1_ptr = new List;
    // list2_ptr = new List;

    memset(list1_ptr, 0, sizeof(List));

    cin >> list1_ptr->number;

    // 如果每次新节点的元素number大于0，则增加节点
    // 初始化状态下head为NULL，第一次循环，head==NULL，将head
    // 指向节点list1_ptr，并将list2_ptr指向list1_ptr，这样list2_ptr
    // 与head指向同一个节点；第二次循环，将list2_ptr->next指向新产生
    // 的节点list1_ptr，这样相当于将head->next指向了新的list1_ptr，然后
    // 将list2_ptr指向list1_ptr；第三次循环，将list2_ptr->next指向新产生
    // 的节点list1_ptr，实际是将第二个节点的next指针指向了新产生的list1_ptr
    // 这样就构成了链表
    while (list1_ptr->number > 0)
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

        list1_ptr = new List;  // 将list1_ptr当成每次添加的新节点
        memset(list1_ptr, 0, sizeof(List));
        cin >> list1_ptr->number;

        list1_ptr->next = NULL;
    }

    return head;
}

void PrintList(List* head)
{
    if (head == NULL)
    {
        cout << "链表为空" << endl;
    }
    else
    {


        while (head != NULL)
        {
            cout << head->number << endl;

            // 在函数中修改指针本身，不会影响函数外部的实参指针
            head = head->next;
        }
    }

}

// 链表反序
List* ReverseList(List* head)
{
    if (head == NULL)
    {
        cout << "链表为空" << endl;
        return head;
    }

    List* p1 = NULL;
    List* p2 = NULL;
    List* p3 = NULL;

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

    // 原链表的头节点为反序后新链表的尾节点，所以head->next指向NULL
    head->next = NULL;

    // p1会最终指向原链表的尾节点，即新链表的头节点，所以将head指向p1
    head = p1;

    return head;
}

// 返回倒数第k个节点的值
// 遍历时维持两个指针，第一个指针从链表的头指针开始遍历，在第k-1步之前，第二个指针保持不动；
// 在第k-1步开始，第二个指针也开始从链表的头指针开始遍历。由于两个指针的距离保持在k-1，
// 当第一个（走在前面的）指针到达链表的尾结点时，第二个指针（走在后面的）指针正好是倒数第k个结点。
// 这种思路只需要遍历链表一次。
int findNode(List*head, unsigned int k)
{
    List* p = head;  // 第二个节点
    List* q = head;  // 第一个节点

    for (int i = 0; i < k; ++i)
    {
        q = q->next;
    }

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    return p->number;
}

