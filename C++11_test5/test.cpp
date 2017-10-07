// Copyright 2017.���|�|
// author�����|�|
// �µĹ��캯��
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class Test {
public:
    // ʹ��Ĭ�Ϲ��캯��
    Test() = default;
};

class Test1
{
public:
    Test1(string no, int count) : book_no_(no), count_(count)
    {
        cout << "constructor Test1(string no, int count)" << endl;
    }

    // ί�й��캯��
    // ��ʼ���б�ֻ���Ǳ�ί�еĹ��캯��
    // �����������ĳ�ʼ������
    Test1() : Test1("", 0)
    {
        cout << "default constructor" << endl;
    }

    Test1(string no) : Test1()
    {
        cout << "constructor Test1(string no)" << endl;
        cout << no << " is not used" << endl;
    }

private:
    string book_no_;
    int count_;
};

class Test2
{
public:
    // constexpr�����ʼ�����еĳ�Ա����
    // ��ʼ��ֵ��һ���������ʽ��constexpr
    // ���캯�������ĳЩ�����͵ĳ�Ա������
    constexpr Test2(bool hw, bool io, bool other)
        : hw_(hw), io_(io), other_(other)
    {

    }
private:
    bool hw_;
    bool io_;
    bool other_;
};

int main(int argc, char* argv[])
{
    Test t;

    // ί�й���
    Test1 t1;
    cout << endl;
    Test1 t2("1234");
    return 0;
}
