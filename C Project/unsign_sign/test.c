#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned char a = 128;
    char b = a;
    short c = b;

    printf("%d\n", (int)a);  // 128
    printf("%d\n", c);  // -128

    // �޷����ַ�a�Ĳ���Ϊ10000000
    // ���з����ַ���������ֵΪ-128
    // ��16λ��-128��ԭ��Ϊ10000000 1000 0000
    // �䲹��Ϊ1111111110000000��������洢���ǲ��룩�������޷�������Ϊ65408
    printf("%d\n", (unsigned short)c);  // 65408

    return 0;
}
