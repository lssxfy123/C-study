// Copyright 2017.刘珅珅
// author：刘珅珅
// chrono程序库：duration(时间段)
#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;

// 重载输出运算符<<
template <typename V, typename R>
ostream& operator << (ostream& s, const chrono::duration<V, R>& dur)
{
    s << "[" << dur.count() << " of " << R::num << "/" << R::den << " ]" << endl;
    return s;
}

int main(int argc, char* argv[])
{
    // duration
    chrono::duration<int> five_seconds(5);  // 5秒，默认单位为秒
    chrono::duration<double, ratio<60>> half_minute(0.5);  // 半分钟, ratio<60>表示1分钟
    chrono::duration<long, ratio<1, 1000>> one_millisecond(1);  // 1毫秒，ratio<1. 1000>表示1毫秒

    // duration的算术运算
    chrono::seconds d1(42);  // 42秒
    chrono::milliseconds d2(10);
    chrono::milliseconds d3 = d1 - d2;
    cout << d3.count() << endl;  // 41990毫秒

    chrono::duration<int, ratio<1, 3>> d4(1);  // 1/3秒
    chrono::duration<int, ratio<1, 5>> d5(1);  // 1/5秒
    // chrono::seconds d6 = d4 + d5;  // error，时间单位不匹配
    chrono::duration<int, ratio<1, 15>> d6 = d4 + d5;  // ok
    cout << d6.count() << endl;  // 8

    // 时间单位匹配
    chrono::seconds ten_seconds(10);
    cout << ten_seconds << endl;
    chrono::hours one_hour(1);
    chrono::seconds d7 = one_hour;  // ok，小时到秒可以转换
    cout << d7.count() << endl;  // 3600
    // chrono::hours d8 = ten_seconds;  // error，秒到小时无法隐式转换

    // 强制从小时间单位转换到大时间单位
    chrono::seconds seconds(65);
    chrono::minutes minute = chrono::duration_cast<chrono::minutes>(seconds);
    cout << minute << endl;  // [1 of 60/1]

    // 时间的切割
    // C++标准库 第2版.pdf上5.7.2的例子有点问题
    return 0;
}
