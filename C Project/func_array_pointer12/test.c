// Copyright 2017.刘珅珅
// author：刘珅珅
// 字符串指针
#include <stdio.h>

int main(int argc, char* argv[])
{
    char* str = "abc";  // 等同于const char* str = "abc";
    // str[0] = 'p';  // error，编译时没问题，运行时程序崩溃

    char strArray[4] = "abc";

    strArray[2] = 'p';

    // 字符串"abc"保存在常量区，里面的内容不允许修改，其
    // 本身是常量指针，定义char* str = "abc";相当于str指向
    // 一个字符串常量，所以不能修改其值；而定义char strArray[4] = "abc";
    // strArray存放在栈区，所以是将字符指针"abc"的值复制给了strArray数组
    // 修改的是存放在栈的字符串"abc"
    printf("%s\n", strArray);  // abp
    return 0;
}

