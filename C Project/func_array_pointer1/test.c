#include <stdio.h>
#include <malloc.h>

// void func(int i = 10);  // 在C语言中不允许定义默认参数的函数
extern int n;

int* p = NULL;

void func1(int k);
void func(int i);

int main(int argc, char* argv[])
{
    int k = 100;
    p = (int*)malloc(2 * sizeof(int));
    // func();
    func(k);
    func(n);
    func1(n);

    p[0] = 1;
    p[1] = 2;

    printf("%d, %d\n", p[0], p[1]);
    return 0;
}

void func(int i)
{
    static int a;
    ++a;
    --i;
    ++n;
    printf("%d\n", i);
    printf("a = %d\n", a);
    printf("p = %d\n", p[0]);
}
