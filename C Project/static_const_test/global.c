
#include <stdio.h>
#include "global.h"

extern int k;

const int m = 8;  // �����m��a.c�ļ��ж����mû���κι�ϵ
extern int n = 9;  // �����n��a.c�ļ��ж����nû���κι�ϵ

void func()
{
    printf("��̬����i = %d\n", i);
    printf("ȫ�ֱ���k = %d\n", k);
    printf("��̬����m = %d\n", m);
}
