#include <stdio.h>

#define MAX 30

#define USER 0

int main(int argc, char* argv[])
{

#if MAX > 10
    printf("MAX ����1\n");
#else
    printf("MAX С��10");

#endif

#ifdef USER
    printf("��USER֮ǰ�Ѷ���\n");
#else
    printf("��USER֮ǰδ����\n");
#endif
    return 0;
}
