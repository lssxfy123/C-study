
// Copyright 2017.刘珅珅
// author：刘珅珅
// C文件操作
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i = 0;
    FILE* file = NULL;
    char* str = "中国梦";
    char str1[10] = {0};

    // 写入文件
    if (fopen_s(&file, "test.txt", "w") != 0)
    {
        printf("不能打开文件\n");
        return 0;
    }

    // fwrite(str, sizeof(str), 1, file);
    fprintf_s(file, "%s", str);
    fclose(file);

    // 读取文件
    if ((fopen_s(&file, "test.txt", "r")) != 0)  // 注意使用"\\"
    {
        printf("不能打开文件\n");
        return 0;
    }

    fscanf(file, "%s", str1);
    //while (EOF != )
    //{
    //    ++i;
    //    // printf("%s\n", str1);
    //}

    printf("%s\n", str1);
    printf("%d\n", i);
    return 0;
}
