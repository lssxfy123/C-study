#include "lnode.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��ʼ���������õ�����ı�ͷָ��Ϊ��
void InitList(Node** head)
{
    *head = NULL;
    printf("��ʼ���ɹ�\n");
}

// ��������
Node* CreateList(Node* head)
{
    Node* pointer_new;
    Node* pointer_temp;

    pointer_new = (Node*)malloc(sizeof(Node));

    if (pointer_new == NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(0);
    }

    memset(pointer_new, 0, sizeof(Node));
    scanf("%d", &pointer_new->data);

    while (pointer_new->data > 0)
    {
        if (head == NULL)  // �ձ�
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
            printf("�ڴ����ʧ��\n");
            exit(0);
        }

        memset(pointer_new, 0, sizeof(Node));
        scanf("%d", &pointer_new->data);
        pointer_new->next = NULL;
    }

    return head;
}

// ��������
void PrintList(Node* head)
{
    if (head == NULL)
    {
        printf("����Ϊ��\n");
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

// �������
// ����ʹ��˫��ָ�룬�����ں������޸�head�����޷��ı亯���ⲿ��ʵ��
// �����ϣ��ʹ��˫��ָ�룬�����������ClearList1����������һ��Nodeָ��
void ClearList(Node** head)
{
    Node* next_ptr;

    if (*head == NULL)
    {
        printf("����Ϊ��\n");
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
//        printf("����Ϊ��\n");
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


// ����ڵ㣬�ڵ�position��λ��
// �ڲ����Լ������ɾ���ڵ�ʱ������Ҫ����õ�ǰ�ڵ�ĺ�̽ڵ�
void InsertNode(Node** head, int position)
{
    //if (head == NULL)
    //{
    //    printf("����Ϊ��\n");
    //    return;
    //}

    Node* inster_node_ptr = NULL;
    Node* p1 = NULL;
    Node* p2 = NULL;
    int index = 0;
    int list_size = SizeList(*head);

    if ((position < 0) || (position > list_size))
    {
        printf("����λ��ѡ������");
        return;
    }

    inster_node_ptr = (Node*)malloc(sizeof(Node));

    printf("���������ڵ�����ݣ�\n");
    scanf("%d", &inster_node_ptr->data);

    if (position == 0)  // �����ͷ
    {
        inster_node_ptr->next = *head;
        *head = inster_node_ptr;
        return;
    }

    p1 = *head;

    // ���Ҵ�����λ�õ��ϼ��ڵ�
    // ���磺position = 1�����ʾҪ�����λ��Ϊ����ĵ�2��λ�ã����ϼ��ڵ�Ϊ*head
    while (index != (position - 1))
    {
        p1 = p1->next;
        ++index;
    }

    p2 = p1->next;  // ���������λ�õ�ԭʼ�ڵ�

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

// ɾ���ڵ㣬ɾ����i���ڵ�
void DeleteNode(Node** head, int i)
{
    Node* inster_node_ptr = NULL;
    Node* p1 = NULL;
    Node* p2 = NULL;
    int index = 0;
    int list_size = SizeList(*head);

    if ((i < 0) || (i > (list_size - 1)))
    {
        printf("ɾ��λ������");
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

    while (index != (i - 1))  // ���Ҵ�ɾ��λ�õ��ϼ��ڵ�
    {
        p1 = p1->next;
        ++index;
    }

    p2 = p1->next;  // ȡ����ɾ���Ľڵ�
    p1->next = p2->next;  // ����ɾ���ڵ���ϼ��ڵ��nextָ��ָ���ɾ���ڵ�ĺ�̽ڵ�
    free(p2);
}

