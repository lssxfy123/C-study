// Copyright 2017.���|�|
// author�����|�|
// ���캯����һ���Գ�ʼ��
#include <iostream>
using namespace std;

class P1
{
public:
    P1(int a, int b)
    {
        cout << "p1 constructor" << endl;
    }
};

class P2
{
public:
    P2(int a, int b)
    {
        cout << "p2 constructor" << endl;
    }

    // ��ֵ��
    P2(initializer_list<int> list)
    {
        cout << "p2 initializer list" << endl;
    }
};

int main(int argc, char* argv[])
{
    P1 p(3, 4);  // ok
    P1 p1{ 4, 5 };  // ok

    // ������캯������һ��explicit�ؼ���
    // �˴��ᱨ�����ܽ�����ʽת��
    P1 p2 = { 5, 6 };  // ok����������ʽת��

    P2 p3(1, 2);  // p2 constructor
    P2 p4{ 3, 4 };  // p2 initializer list
    P2 p5{ 5, 6, 7, 8 };  // p2 initializer list
    return 0;
}
