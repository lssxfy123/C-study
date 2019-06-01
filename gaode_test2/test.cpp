// Copyright 2019.���|�|
// author�����|�|
// C++����ǿ������ת��
// const_cast
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    const int i = 10;
    // int& r = i;  // error����ֵ�����޷��󶨳���
    int& r = const_cast<int&>(i);  // ok
    r = 100;

    // ͨ�������޸���r��i��δ�����仯
    // �������ڶ���const������������������Ż���
    // �������Ĵ����У�ÿ��ʹ��ֱ�ӴӼĴ���ȡֵ
    // ��ʹ���ڴ����޸�������ֵ��������Ҳ�޷�֪��
    cout << "r = " << r << endl;  // 100
    cout << "i = " << i << endl;  // 10

    // ʹ��volatile�ؼ��֣���֤������
    // ÿ��ʹ�ö����ڴ���ȡֵ
    const volatile int j = 10;
    int& r1 = const_cast<int&>(j);
    r1 = 100;
    cout << "r1 = " << r1 << endl;  // 100
    cout << "j = " << j << endl;  // 100
    return 0;
}
