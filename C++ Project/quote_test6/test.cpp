// Copyright 2017.���|�|
// author�����|�|
// ���ط����úͷ�������
#include <iostream>

int n = 8;

int& func1();
int& func2();

int main(int argc, char* argv[])
{
    int& a = func1();
    int& b = func2();

    std::cout << a << std::endl;  // ���aʱ��Ϊ�������������a�󶨵���ʱ������ʧ��

    int c = func1();
    std::cout << c << std::endl;  // ���c = 5

    func2() = 9;  // ��������Ϊ����ʱ������������Ϊ��ֵ

    std::cout << n << std::endl;  // nΪ9
    return 0;
}

int& func1()
{
    int a = 5;
    return a;  // ��������˷��ؾֲ����������
}

int& func2()
{
    return n;
}
