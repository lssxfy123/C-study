// Copyright 2017.���|�|
// author�����|�|
// chrono����⣺duration(ʱ���)
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;

// ������������<<
template <typename V, typename R>
ostream& operator << (ostream& s, const chrono::duration<V, R>& dur)
{
    s << "[" << dur.count() << " of " << R::num << "/" << R::den << " ]" << endl;
    return s;
}

int main(int argc, char* argv[])
{
    // duration
    chrono::duration<int> five_seconds(5);  // 5�룬Ĭ�ϵ�λΪ��
    chrono::duration<double, ratio<60>> half_minute(0.5);  // �����, ratio<60>��ʾ1����
    chrono::duration<long, ratio<1, 1000>> one_millisecond(1);  // 1���룬ratio<1. 1000>��ʾ1����

    // duration����������
    chrono::seconds d1(42);  // 42��
    chrono::milliseconds d2(10);
    chrono::milliseconds d3 = d1 - d2;
    cout << d3.count() << endl;  // 41990����

    chrono::duration<int, ratio<1, 3>> d4(1);  // 1/3��
    chrono::duration<int, ratio<1, 5>> d5(1);  // 1/5��
    // chrono::seconds d6 = d4 + d5;  // error��ʱ�䵥λ��ƥ��
    chrono::duration<int, ratio<1, 15>> d6 = d4 + d5;  // ok
    cout << d6.count() << endl;  // 8

    // ʱ�䵥λƥ��
    chrono::seconds ten_seconds(10);
    cout << ten_seconds << endl;
    chrono::hours one_hour(1);
    chrono::seconds d7 = one_hour;  // ok��Сʱ�������ת��
    cout << d7.count() << endl;  // 3600
    // chrono::hours d8 = ten_seconds;  // error���뵽Сʱ�޷���ʽת��

    // ǿ�ƴ�Сʱ�䵥λת������ʱ�䵥λ
    chrono::seconds seconds(65);
    chrono::minutes minute = chrono::duration_cast<chrono::minutes>(seconds);
    cout << minute << endl;  // [1 of 60/1]

    // ʱ����и�
    // C++��׼�� ��2��.pdf��5.7.2�������е�����
    return 0;
}
