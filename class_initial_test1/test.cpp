// Copyright 2017.���|�|
// author�����|�|
// ���г�Ա�ĳ�ʼ��
#include <iostream>
using namespace std;

// C98��
// C11�¿��Գ�ʼ��
class Test
{
private:
    // static int a = 0;  // error
    const static int b = 3;
    // const static double c = 3.5;  // error
    const static char d = 'a';  // ok��charҲ���Կ�������
    // const static char* str = "abc";  // error
    // const static char[b] = 'ac';  // error
};

int main(int argc, char* argv[])
{
    // ���������Կ�����ֻ��const static�����ͱ������ַ��ͱ����ſ����������г�ʼ��
    // �ο�http://www.cnblogs.com/good90/archive/2012/03/19/2405757.html
    return 0;
}
