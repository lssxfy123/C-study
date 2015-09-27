// Copyright 2015.���|�|
// author�����|�|
// ������

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

// ��������
List* CreateList(List* head)
{
    List* list1_ptr = NULL;
    List* list2_ptr = NULL;

    list1_ptr = new List;
    // list2_ptr = new List;

    memset(list1_ptr, 0, sizeof(List));

    cin >> list1_ptr->number;

    // ���ÿ���½ڵ��Ԫ��number����0�������ӽڵ�
    // ��ʼ��״̬��headΪNULL����һ��ѭ����head==NULL����head
    // ָ��ڵ�list1_ptr������list2_ptrָ��list1_ptr������list2_ptr
    // ��headָ��ͬһ���ڵ㣻�ڶ���ѭ������list2_ptr->nextָ���²���
    // �Ľڵ�list1_ptr�������൱�ڽ�head->nextָ�����µ�list1_ptr��Ȼ��
    // ��list2_ptrָ��list1_ptr��������ѭ������list2_ptr->nextָ���²���
    // �Ľڵ�list1_ptr��ʵ���ǽ��ڶ����ڵ��nextָ��ָ�����²�����list1_ptr
    // �����͹���������ָ��洢��Ϊ��ַ
    while (list1_ptr->number > 0)
    {
        if (head == NULL)
        {
            head = list1_ptr;
        }
        else
        {
            // ��һ���ڵ��nextָ���µĽڵ�
            // list2_ptr�洢������һ���ڵ�
            list2_ptr->next = list1_ptr;
        }

        // list2_ptr�൱��һ����ʱ�ڵ�
        // �޸�list2_ptr->next��ʵ����
        // �޸������еĽڵ��nextָ��
        list2_ptr = list1_ptr;

        list1_ptr = new List;  // ��list1_ptr����ÿ����ӵ��½ڵ�
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
        cout << "����Ϊ��" << endl;
    }
    else
    {


        while (head != NULL)
        {
            cout << head->number << endl;

            // �ں������޸�ָ�뱾������Ӱ�캯���ⲿ��ʵ��ָ��
            head = head->next;
        }
    }

}

// ������������ϲ�
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

    // �ҳ����������С��ͷ�ڵ㣬head��¼ͷ�ڵ�
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

    //�����������б����Ƚϣ���ֵ��С�Ľ�����ӵ�pcur����
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

    //��p��qʣ��Ľ������pcur֮����������ϲ��Ĺ���
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

