// sunday字符串匹配算法
// 参考：http://blog.chinaunix.net/uid-28216282-id-3623063.html
// 参考：http://www.hoverlees.com/blog/?p=1328

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
    //字符串测试
    char* gbk_src = "cc严中国，严中国人中国人";
    char* gbk_dest = "严中国人";

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

    //内存块测试
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
    // 单个无符号字符串的值在0-255
    int marks[256];
    int i, j, k;
    int result_index = -1;

    for (i = 0; i < 256; ++i)
    {
        marks[i] = -1;
    }

    // 将待查找的字符串dest标记存入到marks数组中
    // 存入的是每个字符的移动步长
    for (i = dest_length - 1; i >= 0; --i)
    {
        if (marks[dest[i]] == -1)  // 防止重复的字符
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
            if (src[i + k] != dest[k])  // 如果发生不匹配
            {
                break;
            }
        }

        if (k == dest_length)
        {
            result_index = i;
            return result_index;
        }

        // 查找在源字符串中，待搜索的字符串长度后一位的字符对应的标记
        k = marks[src[i + dest_length]];
        if (k == -1)  // 如果该字符串不存在于待搜索的字符串中
        {
            i = i + dest_length + 1;  // 直接将待搜索的字符串右移本身长度+1位
        }
        else {  // 如果存在
            i = i + k;  // 待搜索字符串右移该字符对应的标记
        }
    }

    return result_index;
}
