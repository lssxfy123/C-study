// Copyright 2017.���|�|
// author�����|�|
// �ַ�������
// #include <assert.h>
#include <stdio.h>
// #include <string.h>

int Strcat(char* dest, unsigned int length, char* src);

int main(int argc, char* argv[])
{
    // char* str1 = "abc";
    char str1[10] = "abc";
    char* str2 = "def";
    // char* str = NULL;

    Strcat(str1, sizeof(str1), str2);
    // strcat_s(str1, sizeof(str1), str2);

    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}

int Strcat(char* dest, unsigned int length, char* src)
{
    unsigned int dest_length = 0;
    unsigned int src_length = 0;
    char* p = dest;
    char* q = src;

    if (!dest)
    {
        printf("destָ����Ч\n");
        return 0;
    }

    if (!src)
    {
        printf("srcָ����Ч\n");
        return 0;
    }

    // ����dest���ַ�������
    while ((*p) != '\0')
    {
        ++p;
        ++dest_length;
    }

    // ����src���ַ�������
    while ((*q) != '\0')
    {
        ++q;
        ++src_length;
    }

    printf("dest length = %d, src length = %d length = %u\n", dest_length, src_length, length);

    if (length < (dest_length + src_length + 1))
    {
        printf("ָ���ĳ����޷�����dest��src\n");
        return 0;
    }

    while ((*dest) != '\0')
    {
        ++dest;
    }

    while ((*src) != '\0')
    {
        *dest = *src;
        ++dest;
        ++src;
    }

    //while (*dest++ = *src++)
    //{
    //}

    return 1;
}
