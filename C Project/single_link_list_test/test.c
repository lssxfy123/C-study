// Copyright 2017.���|�|
// author�����|�|
// ������
#include <stdio.h>
#include "lnode.h"

int main(int argc, char* argv[])
{
    Node* list = NULL;

    InitList(&list);
    list = CreateList(list);
    PrintList(list);

    InsertNode(&list, 4);

    printf("����ڵ�������\n");
    PrintList(list);

    printf("ɾ���ڵ�������\n");
    DeleteNode(&list, 5);
    PrintList(list);

    ClearList(&list);
    // list = ClearList1(list);
    PrintList(list);
    return 0;
}
