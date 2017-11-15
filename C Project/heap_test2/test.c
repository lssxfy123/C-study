// 堆内存分配

#include <malloc.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    char* p = (char*)malloc(4 * sizeof(char));
    char* p1 = (char*)malloc(4 * sizeof(char));

    // 不能这样为堆内存的指针赋值
    // ++p这个操作移动了p的初始地址
    // 在后续执行free(p)时就会报错
    //for (i = 0; i < 3; ++i)
    //{
    //    *p = 'a';  
    //    ++p;
    //}
    //*p = '\0';

    // 可以像下面这样进行赋值
    for (i = 0; i < 3; ++i)
    {
        *(p + i) = 'a';
    }
    *(p + 3) = '\0';

    for (i = 0; i < 3; ++i)
    {
        p1[i] = 'b';
    }
    p1[i] = '\0';

    printf("%s\n", p);
    free(p);
    p = NULL;

    printf("%s\n", p1);
    free(p1);
    p1 = NULL;

    return 0;
}
