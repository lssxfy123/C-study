// Copyright 2017.刘珅珅
// author：刘珅珅
// C语言中的文件写入
#include <stdio.h>

int main()
{
    FILE* fp = NULL;

    // 没有文件会自动创建
    // 文件已存在不会覆盖
    // 之前的内容，会接着写
    fp = fopen("11.txt", "at+");
    if (fp == NULL) return -1;
    fprintf(fp, "%s", "abcd\n");
    fclose(fp);
    return 0;
}