// ���ڴ����

#include <malloc.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    char* p = (char*)malloc(4 * sizeof(char));
    char* p1 = (char*)malloc(4 * sizeof(char));

    // ��������Ϊ���ڴ��ָ�븳ֵ
    // ++p��������ƶ���p�ĳ�ʼ��ַ
    // �ں���ִ��free(p)ʱ�ͻᱨ��
    //for (i = 0; i < 3; ++i)
    //{
    //    *p = 'a';  
    //    ++p;
    //}
    //*p = '\0';

    // �����������������и�ֵ
    for (i = 0; i < 3; ++i)
    {
        *(p + i) = 'a';
    }
    *(p + 3) = '\0';

    for (i = 0; i < 3; ++i)
    {
        p1[i] = 'b';
    }
    p1[i] = '\0';

    printf("%s\n", p);
    free(p);
    p = NULL;

    printf("%s\n", p1);
    free(p1);
    p1 = NULL;

    return 0;
}
