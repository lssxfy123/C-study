// ָ���뺯��

#include <stdio.h>

int (*pf) (float);  // ����ָ��
int func(float b);


int main(int arg, char* argv)
{
    float a = 2.5;
    int b;
    int c;
    pf = func;

    b = pf(a);
    c = func(a);

    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}

int func(float b)
{
    return (int)b;
}
