// Copyright 2018.���|�|
// author�����|�|
// ȡģ�����
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // һ������£�ȡģ�����%�Ľ��
    // �뱻�����ķ�����ͬ
    cout << 7 % 4 << endl;  // 3
    cout << 7 % -4 << endl;  // 3
    cout << -7 % 4 << endl;  // -3
    cout << -7 % -4 << endl;  // -3
	cout << endl;

	cout << 7 / 4 << endl;  // 1
	cout << 7 / -4 << endl;  // -1
	cout << -7 / 4 << endl;  // -1
	cout << -7 / -4 << endl;  // 1
	cout << endl;

	cout << 7 % 8 << endl;  // 7
	cout << 7 % -8 << endl;  // 7
	cout << -7 % 8 << endl;  // -7
	cout << -7 % -8 << endl;  // -7

    // �з��������޷�����ȡģʱ
    // ���з����������޷���������
    int a = -5;
    unsigned int b = 7;
    cout << (unsigned int)a << endl;
    cout << a % b << endl; // 6
    return 0;
}
