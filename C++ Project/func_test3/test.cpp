// 内联函数
#include <iostream>

inline int func(int a);  // 声明为inline后，在定义处可以没有，这一点不同于const函数

int main(int argc, char* argv[])
{
    int a = 1;
    a = func(a);

    return 0;
}

int func(int a)
{
    ++a;
    return a;
}
