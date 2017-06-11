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

    int i = 0;
    string s = "default";

    // 以i,s的引用建立tuple
    auto m = tie(i, s); // m类型为tuple<int&, string&>
    cout << "i: " << get<0>(m) << endl;
    cout << "s: " << get<1>(m) << endl;
    get<0>(m) = 1;
    get<1>(m) = "my value";
    cout << "modify i: " << i << endl;
    cout << "modify s: " << s << endl;

    typedef tuple<int, float, string> TupleType;
    // tuple_size<tupletype>::value获取tuple元素个数
    cout << "tuple count " << tuple_size<TupleType>::value << endl;
    // tuple_element<i, tupletype>::type获取第i个元素的类型
    tuple_element<1, TupleType>::type e1;  // float
    // tuple_cat串接所有形式的tuple
    int n = 0;
    // tt类型为tuple<int, double, const char*, int&>
    auto tt = tuple_cat(make_tuple(42, 7.7, "hello"), tie(n));

    tuple<float, int> t2(4.3f, 3);
    pair<int, float> p1(piecewise_construct, make_tuple(42), make_tuple(4.3f));
    return 0;
}
