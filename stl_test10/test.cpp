// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11 Lambda语法
#include <iostream>
#include <functional>
using namespace std;

// 返回值为Lambda表达式
function<int(int, int)> ReturnLambda()
{
    return[](int x, int y)
    {
        return x * y;
    };
}

int main(int argc, char* argv[])
{
    // lambda表达式
    [] {
        cout << "hello lambda" << endl;
    }();

    auto lambda = [] (const string& str) {
        cout << str.c_str() << endl;
    };
    lambda("test lambda");

    // 带有返回值的Lambda
    auto d_return = []() -> double {
        return 42;
    };
    double d = d_return();
    cout << d << endl;  // 42

    // 使用外部作用域未被传递为实参的数据
    int x = 0;
    int y = 42;

    // x以值传递传递给lambda，是可读数据，但不能改变
    // y以引用传递给lambda，可以改变它
    auto qqq = [x, &y] {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        // ++x;  // error，不能改变x的值
        ++y;
    };

    x = y = 77;
    qqq();
    qqq();
    cout << "final y: " << y << endl;

    // 可变Lambda，可以修改按值传递的外部作用域变量
    int id = 0;
    auto lambda_mutable = [id] () mutable {
        cout << "id: " << id << endl;
        ++id;
    };
    id = 42;
    lambda_mutable();
    lambda_mutable();
    cout << "extern id: " << id << endl;

    auto lf = ReturnLambda();
    cout << lf(6, 7) << endl;
    return 0;
}
