// Copyright 2017.刘珅珅
// author：刘珅珅
// 单链表
#include <stdio.h>
#include "lnode.h"

int main(int argc, char* argv[])
{
    Node* list = NULL;

    InitList(&list);
    list = CreateList(list);
    PrintList(list);

    InsertNode(&list, 4);

    printf("插入节点后的链表：\n");
    PrintList(list);

    printf("删除节点后的链表：\n");
    DeleteNode(&list, 5);
    PrintList(list);

    ClearList(&list);
    // list = ClearList1(list);
    PrintList(list);
    return 0;
}
