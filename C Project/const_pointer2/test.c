// constָ�����������β�

#include <stdio.h>

void func(const int* p)
{
    // *p = 4;  // error�������޸�pָ��Ķ���
    // p = NULL;  // �����޸�pָ�뱾��
    printf("%d\n", *p);
}

int main(int argc, char* argv[])
{
    int a = 2;
    int* p = &a;

    func(p);

    return 0;
}
