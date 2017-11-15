#include <iostream>
#include <locale>
using std::cout;
using std::wcout;
using std::endl;
using namespace std;

void reverse(wchar_t* str);

locale loc("chs");

int main(int argc, char* argv[])
{
    //// 这里必须是数组
    //// 参考C语言学习13-数组、指针与函数.docx
    //// 如果定义成char* str = "abcde"，运行会报错
    //// 原因是指针指向的为常量字符串，不能修改其值
    //// 定义成数组则不会有问题，数组存放在栈上
    //// char str[] = "abcde";
    wchar_t str[] = L"A北京欢迎你";  // 需要加L，表示宽字符
    // cout << wcslen(str) << endl;
    reverse(str);

    wcout.imbue(loc);
    wcout << str << endl;
    return 0;
}

void reverse(wchar_t* str)
{
    int length = 0;
    wchar_t* temp = str;
    wchar_t c;

    if (!str)
    {
        printf("待反转的字符串无效\n");
        return;
    }

    // 判断字符串的长度
    while ((*str) != '\0')
    {
        ++length;
        ++str;
    }

    cout << "length = " << length << endl;

    // printf("length = %d\n", length);

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


