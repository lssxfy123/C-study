// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数模板的测试   
#include <iostream>
using namespace std;

//定义一个函数模板
template <typename T>
void compare(const T &a, const T &b)
{
    //注意C++编程的规范性

    if (a > b)
        cout << "a>b" << endl;
    else if (a < b)
        cout << "a<b" << endl;
    else
        cout << "a=b" << endl;
} 

//定义一个内联函数模板
//注意inline关键字要放在返回类型之前
template <typename T>
inline T min(const T&, const T&)
{

}

int main(int argc, char *argv[])
{
    compare(1, 0);
    compare(2.1, 2.1) ;

    char *str1 = "abcd";
    char *str2 ="efgh";

    compare(*str1, *str2);

    return 0;
}