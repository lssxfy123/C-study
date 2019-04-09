// Copyright 2017.���|�|
// author�����|�|
// C++11������������
#include <iostream>
using namespace std;

void func()
{
	int k = 3;
	constexpr int* p = &k;
}

int main(int argc, char* argv[])
{
    // �µ���������long long
    cout << "int size " << sizeof(int) << endl;
    cout << "long size " << sizeof(long) << endl;
    cout << "long long size " << sizeof(long long) << endl;

    // �б��ʼ��
    int unit_sold = 0;
    int unit_sold1{0};  // �б��ʼ��

    long double ld = 3.1415926536;
    //int a{ld};  // error���б��ʼ������������ת��

    int b = 9;
    // long double ld1{ b };  // error���б��ʼ������������ת��

    // constexpr����ʱ��֤�Ƿ�Ϊ�������ʽ
    constexpr int mf = 20;
    //mf = 4;  // error��mfΪ���ͳ���
    int k = 1;
    //constexpr int limit = k + 1;  // error��k+1��Ϊ�������ʽ
    constexpr double df = 5.5;

    // pΪ����ָ��
    constexpr int* p = &k;
    k = 2;
    cout << *p << endl;  // 2
    // p = nullptr;  // error�����ܸı�p��ָ��
	*p = 3;  // ����ͨ��*�޸�ָ������ֵ
	cout << k << endl;  // 3

	int k1 = 2;
	// ������ָ������ָ��
	const int* p2 = &k1;
	// *p2 = 5;  // error������ͨ��*�޸�ָ��ָ��Ķ���
	p2 = nullptr;  // ����ϰ��ָ�뱾��
	
	func();

    // decltype����ָʾ��
    const int ci = 0;
    decltype(ci) x = 0;  // xΪconst int
    //x = 5;  // error��x�����޸�
    const int& cj = ci;
    decltype(cj) y = x;  // yΪconst int&

    int i = 42;
    int* p1 = &i;
    int& r = i;
    decltype(r + 0) b1;  // ok��decltype(r)Ϊ���ã���r+0��������
    //decltype(*p) c1;  // error��*pΪ�����ò�����decltype���õ�����

    //decltype((i))d;  // error��decltype�ı�������1��������ţ��õ���������
    return 0;
}
