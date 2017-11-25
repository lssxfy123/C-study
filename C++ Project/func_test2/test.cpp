// Copyright 2017.���|�|
// author�����|�|
// C++Ĭ�ϲ����ĺ���
#include <iostream>

void func(int a = 0);

void func1(int b = 5)
{
    ++b;
    std::cout << b << std::endl;
}

// ����������func2���ܹ�������
// void func2(int b, int c = 5);
// void func2(int b = 3, int c = 6);

// void func2(int a = 1, int b, int c = 4, int d = 5);  // error��Ĭ�ϲ�����������������ζ���
void func2(int a, int b = 1, int c = 4, int d = 5)
{
    int sum = a + b + c + d;
    std::cout << sum << std::endl;
}

int main(int argc, char* argv[])
{
    int a = 1;
    int b = 3;

    func();
    func(a);
    func1();

    // func2(a, b);
    func2(a);  // a = 1, b = 1, c = 4, d = 5
    func2(a, b);  // a = 1, b = 3, c = 4, d = 5
    func2(a, b, 2, 6);  // a = 1, b = 3, c = 2, d = 6
    // func2(a, , 2, 4);  // error��ֻ�ܴ�������ƥ��Ĭ�ϲ���

    return 0;
}

void func(int a /* = 0 */)
{
    ++a;
    std::cout << a << std::endl;

}

//void func2(int b, int c /* = 5 */)
//{
//    std::cout << b + c << std::endl;
//}
//
//void func2(int b /* = 3 */, int c /* = 6 */)
//{
//    std::cout << b + c << std::endl;
//}