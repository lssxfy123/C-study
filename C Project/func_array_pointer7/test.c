// �ַ������ַ�ָ��

#include <stdio.h>

void reverse(char* str);

int main(int argc, char* argv[])
{
    char* str = "abcde";
    char str1[] = "abcde";
    char* p = NULL;
    int i;

    for (i = 0; str[i] != '\0'; ++i)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    for (i = 0; *(str + i) != '\0'; ++i)
    {
        printf("%c", *(str + i));
    }
    printf("\n");

    // str[0] = 'p';  // C/C++����ʱ���ᱨ��������ʱ��������
    p = str1;

    *p = 'p';
    reverse(p);
    printf("%s\n", str1);
    printf("%s\n", str1);
    return 0;
}

void reverse(char* str)
{
    int length = 0;
    char* temp = str;
    char c;

    if (!str)
    {
        printf("����ת���ַ�����Ч\n");
        return;
    }

    // �ж��ַ����ĳ���
    while ((*str) != '\0')
    {
        ++length;
        ++str;
    }

    printf("length = %d\n", length);

    str = temp;
    temp = str + length - 1;

    while (temp > str)
    {
        c = *temp;
        *temp = *str;
        *str = c;
        ++str;
        --temp;
        // printf("%c", c);
    }
    // printf("\n");
}
