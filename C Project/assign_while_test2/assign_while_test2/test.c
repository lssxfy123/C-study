// 赋值表达式作为判断条件

#include <stdio.h>

int main(int argc, char* argv[])
{
    char str1[10] = {0};
    char str2[] = "abcde";

    char* p1= str1;
    char* p2 = str2;

    while (*p1++ = *p2++)  // 不能直接使用数组名，因其为指针常量，不能进行++运算
    {
    }

    printf("%s\n", str1);
    return 0;
}
