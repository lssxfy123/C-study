// Copyright 2017.���|�|
// author�����|�|
// ��ֵ���ʽ��Ϊ�ж�����
#include <stdio.h>

int main(int argc, char* argv[])
{
    char str1[10] = {0};
    char str2[] = "abcde";

    char* p1= str1;
    char* p2 = str2;


    // ����ֱ��ʹ��������������Ϊָ�볣�������ܽ���++����
    // p2�����һλΪ'/0'��������*p2��Ϊ0����Ӧ��*p1 = 0
    // whileѭ������
    while (*p1++ = *p2++) 
    {
    }

    printf("%s\n", str1);
    return 0;
}
