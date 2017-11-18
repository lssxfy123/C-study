// Copyright 2017.刘珅珅
// author：刘珅珅
// 编码转换：GBK->UTF8, UTF8->GBK
// http://www.cnblogs.com/KevinYang/archive/2010/06/18/1760597.html
#include <iostream>
#include <string>
#include <windows.h>
#include "../include/print.hpp"
using namespace std;
int GBKToUTF8(const char* src, char* utf8_str, int max_utf_length)
{
    WCHAR* unicode_str = NULL;
    int unicode_length = MultiByteToWideChar(CP_ACP, 0, src, -1, NULL, 0);
    unicode_str = (WCHAR*)malloc(sizeof(WCHAR) * unicode_length);
    MultiByteToWideChar(CP_ACP, 0, src, -1, unicode_str, unicode_length);

    int utf_length = WideCharToMultiByte(CP_UTF8, 0, unicode_str, -1, NULL, 0, NULL, NULL);
    if (utf_length >= max_utf_length)
    {
        return -1;
    }
    WideCharToMultiByte(CP_UTF8, 0, unicode_str, -1, utf8_str, utf_length, NULL, NULL);

    free(unicode_str);
    return utf_length;
}

int UTF8ToGBK(const unsigned char* src, char* gbk_str, int max_gbk_length)
{
    int unicode_length = 0;
    int gbk_length = 0;
    wchar_t* unicode_str = NULL;
    if (!src)
    {
        return -1;
    }

    unicode_length = MultiByteToWideChar(CP_UTF8, 0, (char*)src, -1, NULL, 0);
    unicode_str = (wchar_t*)malloc(unicode_length * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, (char*)src, -1, unicode_str, unicode_length);

    gbk_length = WideCharToMultiByte(CP_ACP, 0, unicode_str, -1, NULL, 0, NULL, NULL);
    if (gbk_length > max_gbk_length)
    {
        free(unicode_str);
        return -1;
    }

    WideCharToMultiByte(CP_ACP, 0, unicode_str, -1, gbk_str, gbk_length, NULL, NULL);

    free(unicode_str);
    return gbk_length;
}

int main(int argc, char* argv[])
{
    char* src = "cc严中国";
    char utf_str[512];
    int utf_length = GBKToUTF8(src, utf_str, 512);
    cout << "utf length " << utf_length << endl;

    for (int i = 0; i < utf_length; ++i)
    {
        unsigned char test = utf_str[i];
        cout << "test char " << (int)test << endl;
    }

    char gbk[512] = { 0 };
    int gbk_length = UTF8ToGBK((unsigned char*)utf_str, gbk, 512);

    cout << "length " << gbk_length << " str " << gbk << " strlen " << strlen(gbk) << endl;

    return 0;
}
