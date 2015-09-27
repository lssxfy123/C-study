// Copyright 2015.刘珅珅
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
List* Merge(List* head1, List* head2);

int main(int argc, char* argv[])
{
    List* head1 = NULL;
    List* head2 = NULL;

    head1 = CreateList(head1);
    PrintList(head1);

    head2 = CreateList(head2);
    PrintList(head2);

    List* head = Merge(head1, head2);
    PrintList(head);

    return 0;
}

// 创建链表
List* CreateList(List* head)
{
    List* list1_ptr = NULL;
    List* list2_ptr = NULL;

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
    // 这样就构成了链表，指针存储的为地址
    while (list1_ptr->number > 0)
    {
        if (head == NULL)
        {
            head = list1_ptr;
        }
        else
        {
            // 上一个节点的next指向新的节点
            // list2_ptr存储的是上一个节点
            list2_ptr->next = list1_ptr;
        }

        // list2_ptr相当于一个临时节点
        // 修改list2_ptr->next，实际是
        // 修改链表中的节点的next指针
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

// 两个有序链表合并
List* Merge(List* head1, List* head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head2;
    }

    List* head = NULL;
    List* p = NULL;
    List* q = NULL;

    // 找出两个链表较小的头节点，head记录头节点
    if (head1->number < head2->number)
    {
        head = head1;
        p = head1->next;
        q = head2;

    }
    else
    {
        head = head2;
        p = head1;
        q = head2->next;

    }

    List* pcur = head;

    //在两个链表中遍历比较，将值较小的结点链接到pcur结点后
    while ((p != NULL) && (q != NULL))
    {
        if (p->number <= q->number)
        {
            pcur->next = p;
            pcur = p;
            p = p->next;
        }
        else
        {
            pcur->next = q;
            pcur = q;
            q = q->next;
        }
    }

    //将p或q剩余的结点链到pcur之后，完成整个合并的过程
    if (p != NULL)
    {
        pcur->next = p;
    }

    if (q != NULL)
    {
        pcur->next = q;
    }

    return head;
}

