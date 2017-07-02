// Copyright 2017.刘珅珅
// author：刘珅珅
// chrono程序库：Timepoint
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

string AsString(chrono::system_clock::time_point& tp)
{
    // 转换系统时间
    time_t t = chrono::system_clock::to_time_t(tp);
    char str[30];
    ctime_s(str, sizeof(str), &t);
    return str;
}

int main(int argc, char* argv[])
{
    // 系统时间的起点
    // 要包含时区的信息
    chrono::system_clock::time_point tp;
    cout << "epoch: " << AsString(tp) << endl;

    // 当前时间
    tp = chrono::system_clock::now();
    cout << "now: " << AsString(tp) << endl;

    // 系统时钟的最小时间
    // 在VS下该值不可见
    tp = chrono::system_clock::time_point::min();
    cout << "min: " << AsString(tp) << endl;

    // 系统时钟的最大时间
    // 在VS下该值不可见
    tp = chrono::system_clock::time_point::max();
    cout << "max: " << AsString(tp) << endl;
    return 0;
}
