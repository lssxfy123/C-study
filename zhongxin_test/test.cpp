// Copyright 2019.���|�|
// author�����|�|
// ���ŵı���
#include <iostream>
using namespace std;

struct Test
{
    int* p;
    int i;
};

class Base
{};

class Derived : public Base
{};

void func(Base b)
{
    // ���۴�����ǻ��໹��������
    // �����Ϊclass Base
    cout << typeid(b).name() << endl;
}

#define N 3
#define Y(n) ((N+1)*n)
#define Y1(n) ((N+1)*(n))

int main(int argc, char* argv[])
{
    int **k, *j, i = 100;
    j = &i;
    k = &j;
    cout << **k << endl;  // 100

    //Test t;
    //int* p = &t.i;
    //p[1] = 1;
    //p[0] = 2;
    //t.p = p;
    //p[1] = 3;
    //p[0] = 4;
    char b[10];
    //b = "Hello";  // error��������Ϊ����ָ�룬�����޸�
    Base base;
    cout << typeid(base).name() << endl;

    Derived d;
    func(d);

    double d1 = 1;
    double g = d1 + 5 / 4;
    cout << g << endl;  // 2.0

    // 2 * (3 + (3 + 1) * 5 + 1)
    cout << 2 * (N + Y(5 + 1)) << endl;  // 48

    // 2 * (3 + (3 + 1) * (5 + 1))
    cout << 2 * (N + Y1(5 + 1)) << endl;  // 54

    char s[] = "xywz";
    cout << sizeof(s) << endl;  // 5
    return 0;
}
