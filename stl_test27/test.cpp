// Copyright 2017.���|�|
// author�����|�|
// chrono����⣺Clockʱ��
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

template <typename T>
void PrintClockData()
{
    cout << "- precison: ";
    typedef typename T::period P;  // ʱ�䵥Ԫ���͵ı���
    // ��ȡʱ�Ӿ���
    // ���ʱ�Ӿ���С��1/1000
    if (ratio_less_equal<P, milli>::value)
    {
        // ��ʱ�Ӿ��ȳ���1000
        typedef typename ratio_multiply<P, kilo>::type TT;
        cout << fixed << double(TT::num) / double(TT::den) << " milliseconds" << endl;
    }
    else {
        cout << fixed << double(P::num) / P::den << " seconds" << endl;
    }

    // �жϸ�ʱ���Ƿ��ȶ�
    // �ȶ���ʱ�ӵ�ϵͳ����ʱ�䳯ǰ������Ҳ�������
    // ���ʺϼ�������ʱ���Ĳ��
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
