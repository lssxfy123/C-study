// Copyright 2017.���|�|
// author�����|�|
// C�����е��ļ�д��
#include <stdio.h>

int main()
{
    FILE* fp = NULL;

    // û���ļ����Զ�����
    // �ļ��Ѵ��ڲ��Ḳ��
    // ֮ǰ�����ݣ������д
    fp = fopen("11.txt", "at+");
    if (fp == NULL) return -1;
    fprintf(fp, "%s", "abcd\n");
    fclose(fp);
    return 0;
}