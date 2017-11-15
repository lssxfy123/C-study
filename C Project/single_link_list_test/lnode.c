#include "lnode.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 初始化链表，即置单链表的表头指针为空
void InitList(Node** head)
{
    *head = NULL;
    printf("初始化成功\n");
}

// 创建链表
Node* CreateList(Node* head)
{
    Node* pointer_new;
    Node* pointer_temp;

    pointer_new = (Node*)malloc(sizeof(Node));

    if (pointer_new == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }

    memset(pointer_new, 0, sizeof(Node));
    scanf("%d", &pointer_new->data);

    while (pointer_new->data > 0)
    {
        if (head == NULL)  // 空表
        {
            head = pointer_new;
        }
        else
        {
            pointer_temp->next = pointer_new;
        }

        pointer_temp = pointer_new;
        pointer_new = (Node*)malloc(sizeof(Node));

        if (pointer_new == NULL)
        {
            printf("内存分配失败\n");
            exit(0);
        }

        memset(pointer_new, 0, sizeof(Node));
        scanf("%d", &pointer_new->data);
        pointer_new->next = NULL;
    }

    return head;
}

// 遍历链表
void PrintList(Node* head)
{
    if (head == NULL)
    {
        printf("链表为空\n");
    }
    else
    {
        while (NULL != head)
        {
            printf("%d\n", head->data);
            head = head->next;
        }
    }
}

// 清空链表
// 必须使用双重指针，否则在函数中修改head本身，无法改变函数外部的实参
// 如果不希望使用双重指针，可以像下面的ClearList1函数，返回一个Node指针
void ClearList(Node** head)
{
    Node* next_ptr;

    if (*head == NULL)
    {
        printf("链表为空\n");
        return;
    }

    while (*head != NULL)
    {
        next_ptr = (*head)->next;
        free(*head);
        *head = next_ptr;
    }
}

//Node* ClearList1(Node* head)
//{
//    Node* next_ptr;
//
//    if (head == NULL)
//    {
//        printf("链表为空\n");
//        return head;
//    }
//
//    while (head != NULL)
//    {
//        next_ptr = head->next;
//        free(head);
//        head = next_ptr;
//    }
//
//    return head;
//}


// 插入节点，在第position个位置
// 在插入以及后面的删除节点时，首先要保存好当前节点的后继节点
void InsertNode(Node** head, int position)
{
    //if (head == NULL)
    //{
    //    printf("链表为空\n");
    //    return;
    //}

    Node* inster_node_ptr = NULL;
    Node* p1 = NULL;
    Node* p2 = NULL;
    int index = 0;
    int list_size = SizeList(*head);

    if ((position < 0) || (position > list_size))
    {
        printf("插入位置选择有误");
        return;
    }

    inster_node_ptr = (Node*)malloc(sizeof(Node));

    printf("请输入插入节点的数据：\n");
    scanf("%d", &inster_node_ptr->data);

    if (position == 0)  // 插入表头
    {
        inster_node_ptr->next = *head;
        *head = inster_node_ptr;
        return;
    }

    p1 = *head;

    // 查找待插入位置的上级节点
    // 例如：position = 1，则表示要插入的位置为链表的第2个位置，其上级节点为*head
    while (index != (position - 1))
    {
        p1 = p1->next;
        ++index;
    }

    p2 = p1->next;  // 保存待插入位置的原始节点

    p1->next = inster_node_ptr;
    inster_node_ptr->next = p2;
}

int SizeList(Node* head)
{
    int size = 0;

    while (head != NULL)
    {
        ++size;
        head = head->next;
    }

    return size;
}

// 删除节点，删除第i个节点
void DeleteNode(Node** head, int i)
{
    Node* inster_node_ptr = NULL;
    Node* p1 = NULL;
    Node* p2 = NULL;
    int index = 0;
    int list_size = SizeList(*head);

    if ((i < 0) || (i > (list_size - 1)))
    {
        printf("删除位置有误");
        return;
    }

    if (i == 0)
    {
        p1 = (*head)->next;
        free(*head);
        *head = p1;
        return;
    }

    p1 = *head;

    while (index != (i - 1))  // 查找待删除位置的上级节点
    {
        p1 = p1->next;
        ++index;
    }

    p2 = p1->next;  // 取出待删除的节点
    p1->next = p2->next;  // 将待删除节点的上级节点的next指针指向待删除节点的后继节点
    free(p2);
}

