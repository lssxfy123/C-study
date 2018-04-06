// Copyright 2017.���|�|
// author�����|�|
// ����
#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int& a_reference = a;  // ���ñ����ʼ��
    // ����һ����ʼ����ֻҪ�����ô��ڣ��ͱ��ְ󶨵���ʼ��ʱָ���Ķ���
    // �����Ƕ������һ�����֣������������ϵ����в������������ڸ�����
    // �󶨵Ķ�����

    int& b_reference = a_reference;
    std::cout << a << std::endl;  // 0
    std::cout << a_reference << std::endl;  // 0
    std::cout << b_reference << std::endl;

    a = 5;
    std::cout << a << std::endl;  // 5
    std::cout << a_reference << std::endl;  // 5
    std::cout << b_reference << std::endl;

    a_reference = 7;
    std::cout << a << std::endl;  // 7
    std::cout << a_reference << std::endl;  // 7
    std::cout << b_reference << std::endl;

    // ���������������ַ��ȫ��ͬ
    std::cout << &a << std::endl;
    std::cout << &a_reference << std::endl;
    std::cout << &b_reference << std::endl;
    return 0;
}

