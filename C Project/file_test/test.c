
// Copyright 2017.���|�|
// author�����|�|
// C�ļ�����
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i = 0;
    FILE* file = NULL;
    char* str = "�й���";
    char str1[10] = {0};

    // д���ļ�
    if (fopen_s(&file, "test.txt", "w") != 0)
    {
        printf("���ܴ��ļ�\n");
        return 0;
    }

    // fwrite(str, sizeof(str), 1, file);
    fprintf_s(file, "%s", str);
    fclose(file);

    // ��ȡ�ļ�
    if ((fopen_s(&file, "test.txt", "r")) != 0)  // ע��ʹ��"\\"
    {
        printf("���ܴ��ļ�\n");
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
