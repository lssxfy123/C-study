
#include <stdio.h>
#include "global.h"

extern int k;

const int m = 8;  // 这里的m与a.c文件中定义的m没有任何关系
extern int n = 9;  // 这里的n与a.c文件中定义的n没有任何关系

void func()
{
    printf("静态变量i = %d\n", i);
    printf("全局变量k = %d\n", k);
    printf("静态常量m = %d\n", m);
}
