// Copyright 2017.���|�|
// author�����|�|
// ָ�������
#include <iostream>

int main(int argc, char* argv[])
{
    int a = 5;
    int& b = a;
    int& c = b;

    // a = 5 b = 5 c = 5
    std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;

    // int* &p = &b;  // error�����õ�ָ�벻����
    int* q = &b;  // ok
    int* p = &a;
    int*& quote_p = p;

    // ����4����ַ��ȫ��ͬ
    std::cout << &a << std::endl;
    std::cout << q << std::endl;
    std::cout << p << std::endl;
    std::cout << quote_p << std::endl;

    int d = 10;
    quote_p = &d;

    // a�ĵ�ַ��p��quote_p��ͬ
    // quote_p��p�ĵ�ַ��ͬ
    std::cout << &a << std::endl;
    std::cout << p << std::endl;
    std::cout << quote_p << std::endl;

    *quote_p = 15;

    std::cout << a << std::endl;  // a = 5
    std::cout << d << std::endl;  // d = 15

    int array[10] = {0};

    int (&quote_array)[10] = array;

    for (int i = 0; i != 10; ++i)
    {
        quote_array[i] = i + 1;
    }

    for (int j = 0; j != 10; ++j)
    {
        std::cout << array[j] << std::endl;
    }

    return 0;
}
