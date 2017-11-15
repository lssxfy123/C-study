#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned char a = 128;
    char b = a;
    short c = b;

    printf("%d\n", (int)a);  // 128
    printf("%d\n", c);  // -128

    // 无符号字符a的补码为10000000
    // 在有符号字符中其代表的值为-128
    // 在16位中-128的原码为10000000 1000 0000
    // 其补码为1111111110000000（计算机存储的是补码），看成无符号数即为65408
    printf("%d\n", (unsigned short)c);  // 65408

    return 0;
}
