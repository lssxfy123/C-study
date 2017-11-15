
#ifndef LNODE_H
#define LNODE_H

typedef struct Node
{
    int data;
    struct Node* next;
}Node;


// ��ʼ���������õ�����ı�ͷָ��Ϊ��
void InitList(Node** head);

// ��������
Node* CreateList(Node* head);

// ��������
void PrintList(Node* head);

// ��ȡ������
int SizeList(Node* head);

// �������
void ClearList(Node** head);
Node* ClearList1(Node* head);

// ����ڵ㣬�ڵ�positon��λ��
void InsertNode(Node** head, int position);

// ɾ���ڵ㣬ɾ����i���ڵ�
void DeleteNode(Node** head, int i);

#endif
