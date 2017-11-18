// sunday�ַ���ƥ���㷨
// �ο���http://blog.chinaunix.net/uid-28216282-id-3623063.html
// �ο���http://www.hoverlees.com/blog/?p=1328

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rect_s {
    float x;
    float y;
};

typedef struct rect_s rect;

int SundaySearch(unsigned char* src, int src_length, unsigned char* dest, int dest_length);

int main(int argc, char* argv[])
{
    int i;
    rect test;
    //�ַ�������
    char* gbk_src = "cc���й������й����й���";
    char* gbk_dest = "���й���";

    char* src = "hoverlee hehe xixi asdfasdfadfasdfashoverleesdi1294871-2alsdkjfzafsd hoverlees";
    char* dest = "hoverlees";
    int result_index = SundaySearch((unsigned char*)src, strlen(src), (unsigned char*)dest, strlen(dest));
    if (result_index == -1)
        printf("not found");
    else
        printf("length %d, result index %d\n", strlen(dest), result_index);

    result_index = SundaySearch((unsigned char*)gbk_src, strlen(gbk_src), (unsigned char*)gbk_dest, strlen(gbk_dest));
    if (result_index == -1)
        printf("not found");
    else
        printf("length %d, result index %d\n", strlen(gbk_dest), result_index);

    //�ڴ�����
    src = (char*)malloc(8196000);
    srand(1234567);
    for (i = 0; i < 8196000; i++) {
        src[i] = rand() % 256;
    }
    dest = (char*)malloc(1024000);
    for (i = 0; i < 1024000; i++) {
        dest[i] = src[1234567 + i];
    }
    result_index = SundaySearch((unsigned char*)src, 8196000, (unsigned char*)dest, 1024000);
    if (result_index == -1)
        printf("not found");
    else
        printf("result index %d\n", result_index);

    free(src);
    free(dest);
    return 0;
}

int SundaySearch(unsigned char* src, int src_length, unsigned char* dest, int dest_length)
{
    // �����޷����ַ�����ֵ��0-255
    int marks[256];
    int i, j, k;
    int result_index = -1;

    for (i = 0; i < 256; ++i)
    {
        marks[i] = -1;
    }

    // �������ҵ��ַ���dest��Ǵ��뵽marks������
    // �������ÿ���ַ����ƶ�����
    for (i = dest_length - 1; i >= 0; --i)
    {
        if (marks[dest[i]] == -1)  // ��ֹ�ظ����ַ�
        {
            marks[dest[i]] = dest_length - i;
        }
    }

    i = 0;
    j = src_length - dest_length + 1;
    while (i < j)
    {
        for (k = 0; k < dest_length; ++k)
        {
            if (src[i + k] != dest[k])  // ���������ƥ��
            {
                break;
            }
        }

        if (k == dest_length)
        {
            result_index = i;
            return result_index;
        }

        // ������Դ�ַ����У����������ַ������Ⱥ�һλ���ַ���Ӧ�ı��
        k = marks[src[i + dest_length]];
        if (k == -1)  // ������ַ����������ڴ��������ַ�����
        {
            i = i + dest_length + 1;  // ֱ�ӽ����������ַ������Ʊ�����+1λ
        }
        else {  // �������
            i = i + k;  // �������ַ������Ƹ��ַ���Ӧ�ı��
        }
    }

    return result_index;
}
