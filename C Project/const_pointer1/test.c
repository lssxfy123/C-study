// constָ��

#include <stdio.h>

int main(int argc, char* argv[])
{
    int a = 58;
    int b = 68;
    int c = 78;
    int d = 88;
    int e = 98;
    int f = 108;

    // ָ������ָ�룬��ָ������ǰ��const��
    // ��ʾָ��ָ��Ķ����ǳ�����ָ�뱾������޸ģ�
    // ��ָ��ָ��Ķ����ǳ������ǲ����޸ĵģ�
    // ��ʹָ�뱾���޸��ˣ�����ָ��Ķ�����Ȼ�ǳ��������ǲ����޸ġ�
    const int* p1 = &a;

    // ��ָ������ָ���÷���ͬ
    int const* p2 = &b;

    // ָ�볣������ָ����ǰ��const����ʾָ�뱾���ǳ�����
    // ָ�뱾�����޸ģ���ָ��ָ��Ķ�������޸ġ�
    int* const p3 = &c;

    //ָ������ָ�볣��
    const int* const p4 = &d;

    // *p1 = 108;  // error��ָ����Ϊconst����
    a = 55;
    p1 = &f;
    p2 = &e;

    // p3 = &f;  // error�������޸�ָ�뱾��
    *p3 = 118;

    printf("%d\n", *p1);
    printf("%d\n", *p2);
    printf("%d, %d\n", *p3, c);

    return 0;
}

