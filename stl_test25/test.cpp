// Copyright 2017.刘珅珅
// author：刘珅珅
// ratio：编译期分数运算
#include <iostream>
#include <limits>
#include <ratio>
using namespace std;

int main(int argc, char* argv[])
{
    typedef ratio<5, 3> FiveThirds;
    cout << FiveThirds::num << "/" << FiveThirds::den << endl;  // 5/3

    typedef ratio<25, 15> AlsoFiveThirds;
    cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << endl;  // 5/3

    ratio<42, 42> one;
    cout << one.num << "/" << one.den << endl;  // 1/1

    ratio<0> zero;
    cout << zero.num << "/" << zero.den << endl;  // 0/1

    typedef ratio<7, -3> Neg;
    cout << Neg::num << "/" << Neg::den << endl;  // -7/3

    // 四则运算
    // 加
    ratio_add<ratio<2, 7>, ratio<2, 6>>::type sum;
    cout << "sum " << sum.num << "/" << sum.den << endl;  // 13/21:6/21 + 7/21

    // 减
    ratio_subtract<ratio<2, 7>, ratio<2, 6>>::type diff;
    cout << "diff " << diff.num << "/" << diff.den << endl;  // -1/21:6/21 - 7/21

    // 乘
    ratio_multiply<ratio<1, 2>, ratio<1, 4>>::type mult;
    cout << "multiply " << mult.num << "/" << mult.den << endl;  // 1/8:1/2 * 1/4

    // 除
    ratio_divide<ratio<1, 2>, ratio<1, 4>>::type div;
    cout << "divide " << div.num << "/" << div.den << endl;  // 2/1: 1/2 / 1/4

    // 是否相等
    if (ratio_equal<ratio<5, 3>, ratio<25, 15>>::value)
    {
        cout << "equal" << endl;
    }
    return 0;
}
