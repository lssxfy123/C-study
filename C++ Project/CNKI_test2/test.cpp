// Copyright 2017.���|�|
// author�����|�|
// �ַ����滻
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

// ��B��src�е�����A�����滻
// ����src�Ĵ洢�ռ��㹻
void Replace(char* src, const char* A, const char* B);

int main(int argc, char* argv[])
{
    char src[100] = "abababababab";
    char* A = "ab";
    char* B = "kk";
    Replace(src, A, B);

    cout << src << endl;
    //char str[] = "������ӭ��";

    //int length = strlen(str);

    ////for (int i = 0; i != length; ++i)
    ////{
    ////    cout << ()str[i] << endl;
    ////}
    //cout << "length = " << length << endl; // 10
    //cout << sizeof(str) << endl;  // 11�������˽����ַ�'\0'
    //cout << str << endl;
    return 0;
}

void Replace(char* src, const char* A, const char* B)
{
    int A_length = strlen(A);
    int B_length = strlen(B);

    // ָ��pָ��src
    // �޸�p��ֵҲ��ı�src��ֵ
    char* p = strstr(src, A);

    //int len = p - src;

    //cout << len << endl;

    while (p != NULL)
    {
        int p_length = strlen(p);
        if (A_length > B_length)
        {
            for (int i = A_length; i <= (p_length); ++i)
            {
                p[i - (A_length - B_length)] = p[i];
            }
        } else if (A_length < B_length)
        {
            // ��Ϊsrc�ĳ����㹻������p���Է��ʵ�����p_length��Χ
            for (int i = p_length; i >= A_length; --i)
            {
                p[i + (B_length - A_length)] = p[i];
            }
        }

        for (int j = 0; j != B_length; ++j)
        {
            p[j] = B[j];
        }

        p = strstr(src, A);
    }
}
