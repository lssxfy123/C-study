
#ifndef LNODE_H
#define LNODE_H

typedef struct Node
{
    int data;
    struct Node* next;
}Node;


// 初始化链表，即置单链表的表头指针为空
void InitList(Node** head);

// 创建链表
Node* CreateList(Node* head);

// 遍历链表
void PrintList(Node* head);

// 获取链表长度
int SizeList(Node* head);

// 清空链表
void ClearList(Node** head);
Node* ClearList1(Node* head);

// 插入节点，在第positon个位置
void InsertNode(Node** head, int position);

// 删除节点，删除第i个节点
void DeleteNode(Node** head, int i);

#endif
