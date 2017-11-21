// Copyright 2017.���|�|
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
List* ReverseList(List* head);

void ListTest(List* head);

int main(int argc, char* argv[])
{
    List* head = NULL;

    head = CreateList(head);
    ListTest(head);
    PrintList(head);

    cout << "������" << endl;
    head = ReverseList(head);
    // ReverseList(head);  // ���������ǲ��Ὣ��������Ϊ�ں������޸�ָ�뱾����û���õ�
    PrintList(head);

    return 0;
}

void ListTest(List* head)
{
    head->number = 1;  // ���޸ĺ����ⲿʵ���е�ֵ
    head = NULL;  // ����Ӱ�캯���ⲿʵ�ε�ֵ
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
    // �����͹���������
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

// ������
List* ReverseList(List* head)
{
    if (head == NULL)
    {
        cout << "����Ϊ��" << endl;
        return head;
    }

    List* p1 = NULL;
    List* p2 = NULL;
    List* p3 = NULL;

    p1 = head;
    p2 = p1->next;

    // p1��ָ��ԭ���е�ǰ�ڵ���ϼ��ڵ�
    // p2��ָ��ԭ���е�ǰ�ڵ�
    // p3��ָ��ԭ���е�ǰ�ڵ�ĺ�̽ڵ�
    for (; p2 != NULL;)
    {
        // ����ǰ�ڵ�p2����һ���ڵ�洢��p3��
        p3 = p2->next;

        // ����ǰ�ڵ�p2��ԭ�ϼ��ڵ�p1���ɺ�̽ڵ�
        p2->next = p1;

        // ��p1ָ��ǰ�ڵ�
        p1 = p2;

        // ��p2ָ��ԭ���е���һ�ڵ�
        p2 = p3;
    }

    // ԭ������½ڵ�Ϊ������������β�ڵ㣬����head->nextָ��NULL
    head->next = NULL;

    // p1������ָ��ԭ�����β�ڵ㣬���������ͷ�ڵ㣬���Խ�headָ��p1
    head = p1;

    return head;
}
