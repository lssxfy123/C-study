// Copyright 2017.刘珅珅
// author：刘珅珅
// tuple
#include <iostream>
#include <complex>
#include <string>
#include <tuple>
using namespace std;

int main(int argc, char* argv[])
{
    // 两个>之间不需要再加空格
    tuple<string, int, int, complex<double>> t;
    tuple<int, float, string> t1(41, 6.3f, "nico");
    cout << "first " << get<0>(t1) << " second " << get<1>(t1) << " third " << get<2>(t1) << endl;

    string str = "default";
    auto x = make_tuple(str);  // x类型为tuple<string>
    get<0>(x) = "my value";
    cout << "x: " << get<0>(x) << endl;
    cout << "str: " << str << endl;

    auto y = make_tuple(ref(str));  // y类型为tuple<string&>
    get<0>(y) = "my value";
    cout << "y: " << get<0>(y) << endl;
    cout << "str: " << str << endl;

    return 0;
}
