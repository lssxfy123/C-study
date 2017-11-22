// Copyright 2017.刘珅珅
// author：刘珅珅
// 字符串替换
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

// 用B将src中的所有A进行替换
// 假设src的存储空间足够
void Replace(char* src, const char* A, const char* B);

int main(int argc, char* argv[])
{
    char src[100] = "abababababab";
    char* A = "ab";
    char* B = "kk";
    Replace(src, A, B);

    cout << src << endl;
    //char str[] = "北京欢迎你";

    //int length = strlen(str);

    ////for (int i = 0; i != length; ++i)
    ////{
    ////    cout << ()str[i] << endl;
    ////}
    //cout << "length = " << length << endl; // 10
    //cout << sizeof(str) << endl;  // 11，加上了结束字符'\0'
    //cout << str << endl;
    return 0;
}

void Replace(char* src, const char* A, const char* B)
{
    int A_length = strlen(A);
    int B_length = strlen(B);

    // 指针p指向src
    // 修改p的值也会改变src的值
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
            // 因为src的长度足够，所以p可以访问到超出p_length范围
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
