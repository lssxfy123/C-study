// Copyright 2017.���|�|
// author�����|�|
// constָ�����������β�
#include <stdio.h>

void func(const int* p)
{
    // *p = 4;  // error�������޸�pָ��Ķ���

    printf("%d\n", *p);

    // �����޸�pָ�뱾��
    // ����Ӱ�쵽�����ʵ��
    p = NULL; 
}

int main(int argc, char* argv[])
{
    int a = 2;
    int* p = &a;

    func(p);
    printf("%d\n", *p);  // 2

    return 0;
}
