// Copyright 2017.���|�|
// author�����|�|
// �ɱ����ģ��
#include <iostream>
#include "../include/print.hpp"
using namespace std;

// �ɱ������ģ��
template<typename T, typename... Args>
class Test
{
};

template<typename T>
ostream& Print(ostream& os, const T& t)
{
    return os << t;
}

// �ɱ��������ģ��
template<typename T, typename... Args>
ostream& Print(ostream& os, const T& t, const Args&... rest)
{
    os << t << ", ";

    // �ݹ����
    return Print(os, rest...);
}

// Args����ģ�����
// rest����ͨ��Args�����Ͷ���ĺ����β�
template<typename T, typename... Args>
void Foo(const T& t, const Args&... rest)
{
    cout << "Args count " << sizeof...(Args) << endl;
    cout << "rest count " << sizeof...(rest) << endl;
}

int main(int argc, char* argv[])
{
    Test<int, string> t1;
    Test<int, int, float> t2;

    Print<int, string>(cout, 1, "ok");
    cout << endl;

    Print<int, string>(cout, 1, "ok", "abc");
    cout << endl;

    Print<int, string, int>(cout, 1, "ok", 4);
    cout << endl;
    Print<int, string, int>(cout, 1, "ok", 4, 5);
    cout << endl;

    // ��ʵ��ʹ���У��ɱ�ģ��������뺯���������Ƕ�Ӧ��
    // ����һ��Ҫģ�������������ģ����������г�����
    // ����������ݺ��������������Զ��Ƶ�ģ�������
    // ��ָ����ģ�������������Ӧ�ĺ�����������Ӧ��
    // ����˳�����һ��
    Foo<int, string, int, float>(1, "ab", 4, 6.5, "ab", 5);
    return 0;
}
