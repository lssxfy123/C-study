#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned char a = 129;
    char b = a;
    short c = b;

    printf("%d\n", (unsigned short)a);  // 129
    printf("%d\n", c);  // -127

    // �޷����ַ�a�Ĳ���Ϊ10000001
    // ���з����ַ���������ֵΪ-127
    // ��16λ��-127��ԭ��Ϊ10000000 0111 1111
    // �䲹��Ϊ11111111 10000001�������޷�������Ϊ65409
    printf("%d\n", (unsigned short)b);  // 65409

    return 0;
}

