// Copyright 2017.刘珅珅
// author：刘珅珅
// chrono程序库：Clock时钟
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

template <typename T>
void PrintClockData()
{
    cout << "- precison: ";
    typedef typename T::period P;  // 时间单元类型的别名
    // 获取时钟精度
    // 如果时钟精度小于1/1000
    if (ratio_less_equal<P, milli>::value)
    {
        // 将时钟精度乘以1000
        typedef typename ratio_multiply<P, kilo>::type TT;
        cout << fixed << double(TT::num) / double(TT::den) << " milliseconds" << endl;
    }
    else {
        cout << fixed << double(P::num) / P::den << " seconds" << endl;
    }

    // 判断该时钟是否稳定
    // 稳定的时钟当系统物理时间朝前拨，它也不会减少
    // 最适合计算两个时间点的差距
    cout << "- is_steady: " << boolalpha << T::is_steady << endl;
}

int main(int argc, char* argv[])
{
    cout << "system clock: " << endl;
    PrintClockData<chrono::system_clock>();
    cout << "high resolution clock: " << endl;
    PrintClockData<chrono::high_resolution_clock>();
    cout << "steady clock: " << endl;
    PrintClockData<chrono::steady_clock>();
    return 0;
}
