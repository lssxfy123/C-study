// Copyright 2017.���|�|
// author�����|�|
// lambda���ʽ
#include <iostream>
#include "../include/print.hpp"
using namespace std;

const int kSize = 8;

int main(int argc, char* argv[])
{
    int size = 5;
    static int size1 = 6;
    string str("abcd");

    // ����size
    // �ֲ���static������Ҫ���벶���б���
    // ȫ�ֱ����;ֲ�static�����Ͳ���Ҫ��
    auto l = [size](const string& a) {
        return a.size() > size && a.size() > kSize && a.size() > size1;
    };
    l(str);  // ����lambda

    // ֵ����
    int v1 = 42;
    auto f1 = [v1]() {
        // v1 = 5;  // error��ֵ����һ�㲻���޸�
        return v1;
    };
    v1 = 0;  // ����Ӱ��lambda���ʽf1ͨ��ֵ�����ȡ��ֵ
    auto t1 = f1();  // t1 = 42
    cout << "t1 = " << t1 << endl;

    // ���ò���
    // ���뱣֤lambda��ִ��ʱ����ı�������
    int v2 = 42;
    auto f2 = [&v2]() {
        return v2;
    };
    v2 = 0;
    auto t2 = f2();  // t2 = 0;
    cout << "t2 = " << t2 << endl;

	int v3 = 5;
	auto t3 = [&v3]() {
		++v3;  // ���ò��������lambda�������޸���ֵ
		return v3;
	};

	cout << "v3 = " << v3 << endl;
	cout << "t3 = " << t3() << endl;

    // ��ʽֵ����
    // ����Ҫָ����Ҫ����ı���
    auto f3 = [=]() {
        return v1;
    };

    // ��ʽ���ò���
    auto f4 = [&]() {
        return v2;
    };

    // �����ʾ�������ʽ����
    // ��ʽ�������ʾ����ķ�ʽ���벻ͬ
    // ��ʽ���������[]�ĵ�1λ
    // v2�Ĳ���ʽ����Ϊ���ò���
    // ��Ϊ��ʽ������ֵ����
    auto f5 = [=, &v2]() {
        return v1 > v2;
    };

    // v2�Ĳ���ʽ����Ϊֵ����
    // ��Ϊ��ʽ���������ò���
    auto f6 = [&, v2]() {
        return v1 > v2;
    };
    return 0;
}
