// Copyright 2017.刘珅珅
// author：刘珅珅
// lambda表达式
#include <iostream>
#include "../include/print.hpp"
using namespace std;

const int kSize = 8;

int main(int argc, char* argv[])
{
    int size = 5;
    static int size1 = 6;
    string str("abcd");

    // 捕获size
    // 局部非static变量需要放入捕获列表中
    // 全局变量和局部static变量就不需要了
    auto l = [size](const string& a) {
        return a.size() > size && a.size() > kSize && a.size() > size1;
    };
    l(str);  // 调用lambda

    // 值捕获
    int v1 = 42;
    auto f1 = [v1]() {
        // v1 = 5;  // error，值捕获一般不能修改
        return v1;
    };
    v1 = 0;  // 不会影响lambda表达式f1通过值捕获获取的值
    auto t1 = f1();  // t1 = 42
    cout << "t1 = " << t1 << endl;

    // 引用捕获
    // 必须保证lambda在执行时捕获的变量存在
    int v2 = 42;
    auto f2 = [&v2]() {
        return v2;
    };
    v2 = 0;
    auto t2 = f2();  // t2 = 0;
    cout << "t2 = " << t2 << endl;

	int v3 = 5;
	auto t3 = [&v3]() {
		++v3;  // 引用捕获可以在lambda函数中修改其值
		return v3;
	};

	cout << "v3 = " << v3 << endl;
	cout << "t3 = " << t3() << endl;

    // 隐式值捕获
    // 不需要指明需要捕获的变量
    auto f3 = [=]() {
        return v1;
    };

    // 隐式引用捕获
    auto f4 = [&]() {
        return v2;
    };

    // 混合显示捕获和隐式捕获
    // 隐式捕获和显示捕获的方式必须不同
    // 隐式捕获必须在[]的第1位
    // v2的捕获方式必须为引用捕获，
    // 因为隐式捕获是值捕获
    auto f5 = [=, &v2]() {
        return v1 > v2;
    };

    // v2的捕获方式必须为值捕获
    // 因为隐式捕获是引用捕获
    auto f6 = [&, v2]() {
        return v1 > v2;
    };
    return 0;
}
