// Copyright 2017.���|�|
// author�����|�|
// chrono����⣺Timepoint
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

string AsString(chrono::system_clock::time_point& tp)
{
    // ת��ϵͳʱ��
    time_t t = chrono::system_clock::to_time_t(tp);
    char str[30];
    ctime_s(str, sizeof(str), &t);
    return str;
}

int main(int argc, char* argv[])
{
    // ϵͳʱ������
    // Ҫ����ʱ������Ϣ
    chrono::system_clock::time_point tp;
    cout << "epoch: " << AsString(tp) << endl;

    // ��ǰʱ��
    tp = chrono::system_clock::now();
    cout << "now: " << AsString(tp) << endl;

    // ϵͳʱ�ӵ���Сʱ��
    // ��VS�¸�ֵ���ɼ�
    tp = chrono::system_clock::time_point::min();
    cout << "min: " << AsString(tp) << endl;

    // ϵͳʱ�ӵ����ʱ��
    // ��VS�¸�ֵ���ɼ�
    tp = chrono::system_clock::time_point::max();
    cout << "max: " << AsString(tp) << endl;
    return 0;
}
