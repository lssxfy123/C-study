// Copyright 2017.���|�|
// author�����|�|
// ģ�幹�캯��
#include <iostream>
using namespace std;

template <class T>
class MyClass {
public:
    // ���캯��
    MyClass()
    {
        cout << "����Ĭ�Ϲ��캯��" << endl;
    }

    // �������캯��
    MyClass(const MyClass<T>& x)
    {
        cout << "���ÿ������캯��" << endl;
    }

    // ��ͬ���͵Ŀ������캯��
    template <class U> MyClass(const MyClass<U>& x)
    {
        cout << "���ò�ͬ�������͵Ŀ������캯��" << endl;
    }
};

int main(int argc, char* argv[])
{
    MyClass<double> d1;
    MyClass<double> d2(d1);
    MyClass<int> i3(d1);
    return 0;
}
