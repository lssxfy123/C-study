#include <stdio.h>

int main(int argc, char* argv[])
{
    unsigned char a = 129;
    char b = a;
    short c = b;

    printf("%d\n", (unsigned short)a);  // 129
    printf("%d\n", c);  // -127

    // 无符号字符a的补码为10000001
    // 在有符号字符中其代表的值为-127
    // 在16位中-127的原码为10000000 0111 1111
    // 其补码为11111111 10000001，看成无符号数即为65409
    printf("%d\n", (unsigned short)b);  // 65409

    return 0;
}

