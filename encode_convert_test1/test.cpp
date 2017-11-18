// Copyright 2017.刘珅珅
// author：刘珅珅
// 编码转换：GBK->UTF8
// http://www.cnblogs.com/KevinYang/archive/2010/06/18/1760597.html
#include <iostream>
#include <string>
#include <windows.h>
#include "../include/print.hpp"
using namespace std;

string GBKToUTF8(const std::string& strGBK)
{
    string strOutUTF8 = "";
    WCHAR* str1;
    int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
    str1 = new WCHAR[n];
    MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
    char * str2 = new char[n];
    WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
    strOutUTF8 = str2;
    delete[]str1;
    str1 = NULL;
    delete[]str2;
    str2 = NULL;
    return strOutUTF8;
}

int main(int argc, char* argv[])
{
    string str = "c严中国";
    string convert = GBKToUTF8(str);

    cout << "convert length " << convert.length() << endl;
    for (int i = 0; i < convert.length(); ++i)
    {
        unsigned char test = convert[i];
        cout << "test char " << (int)test << endl;
    }

    return 0;
}
