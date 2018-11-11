// Copyright 2017.���|�|
// author�����|�|
// ������
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

// ������
ListNode* Partition(ListNode* head, int x)
{
    if (head == nullptr)
    {
        return head;
    }

    // ��1������x�Ľ��
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
        hasHead = true;  // �����1�����С��x��head��㲻��Ҫ����
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
    cout << "������" << endl;
    head = Partition(head, 3);
    PrintList(head);
    cout << endl;
    ListTest(head);
    PrintList(head);
    cout << endl;

    cout << "������" << endl;
    head = ReverseList(head);
    // ReverseList(head);  // ���������ǲ��Ὣ��������Ϊ�ں������޸�ָ�뱾����û���õ�
    PrintList(head);
    cout << endl;

    return 0;
}

void ListTest(ListNode* head)
{
    head->val = 1;  // ���޸ĺ����ⲿʵ���е�ֵ
    head = NULL;  // ����Ӱ�캯���ⲿʵ�ε�ֵ
}

// ��������
ListNode* CreateList(ListNode* head)
{
    ListNode* list1_ptr = NULL;
    ListNode* list2_ptr = NULL;

    list1_ptr = new ListNode;
    // list2_ptr = new List;

    memset(list1_ptr, 0, sizeof(ListNode));

    cin >> list1_ptr->val;

    // ���ÿ���½ڵ��Ԫ��number����0�������ӽڵ�
    // ��ʼ��״̬��headΪNULL����һ��ѭ����head==NULL����head
    // ָ��ڵ�list1_ptr������list2_ptrָ��list1_ptr������list2_ptr
    // ��headָ��ͬһ���ڵ㣻�ڶ���ѭ������list2_ptr->nextָ���²���
    // �Ľڵ�list1_ptr�������൱�ڽ�head->nextָ�����µ�list1_ptr��Ȼ��
    // ��list2_ptrָ��list1_ptr��������ѭ������list2_ptr->nextָ���²���
    // �Ľڵ�list1_ptr��ʵ���ǽ��ڶ����ڵ��nextָ��ָ�����²�����list1_ptr
    // �����͹���������
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

        list1_ptr = new ListNode;  // ��list1_ptr����ÿ����ӵ��½ڵ�
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
        cout << "����Ϊ��" << endl;
    }
    else
    {
        

        while (head != NULL)
        {
            cout << head->val << ",";

            // �ں������޸�ָ�뱾������Ӱ�캯���ⲿ��ʵ��ָ��
            head = head->next;
        }
    }

}

// ������
ListNode* ReverseList(ListNode* head)
{
    if (head == NULL)
    {
        cout << "����Ϊ��" << endl;
        return head;
    }

    ListNode* p1 = NULL;
    ListNode* p2 = NULL;
    ListNode* p3 = NULL;

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
