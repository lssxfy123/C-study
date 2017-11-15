// const指针做函数的形参

#include <stdio.h>

void func(const int* p)
{
    // *p = 4;  // error，不能修改p指向的对象
    // p = NULL;  // 可以修改p指针本身
    printf("%d\n", *p);
}

int main(int argc, char* argv[])
{
    int a = 2;
    int* p = &a;

    func(p);

    return 0;
}
