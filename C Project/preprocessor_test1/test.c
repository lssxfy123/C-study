#include <stdio.h>

#define MAX 30

#define USER 0

int main(int argc, char* argv[])
{

#if MAX > 10
    printf("MAX 大于1\n");
#else
    printf("MAX 小于10");

#endif

#ifdef USER
    printf("宏USER之前已定义\n");
#else
    printf("宏USER之前未定义\n");
#endif
    return 0;
}
