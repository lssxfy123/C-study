// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11引用叠加规则
#include <iostream>
using namespace std;

void Test(int&& v)
{
}

bool IsRightReference(int&& r)
{
    cout << "右值" << endl;
    return true;
}

bool IsRightReference(int& l)
{
    cout << "左值" << endl;
    return false;
}

template<typename T>
void FuncRule1(T& formal_param)
{
    T formal_param1 = 0;
    cout << "验证规则1" << endl;
}

// 形参需要加const
// 接收的实参为右值
template<typename T>
void FuncRule2(const T& formal_param)
{
    T formal_param1 = 0;
    cout << "验证规则2" << endl;
}

template<typename T>
void FuncRule3(T&& formal_param)
{
    int n = 0;
    T formal_param1 = n;
    cout << "验证规则3" << endl;
}

template<typename T>
void FuncRule4(T&& formal_param)
{
    int n = 0;
    T formal_param1 = n;
    cout << "验证规则4" << endl;
}

int main(int argc, char* argv[])
{
    int a = 1;
    int&& r = 3;
    //Test(a);  // error，右值引用无法绑定到左值
    //Test(r);  // error，右值引用无法绑定到左值

    // 引用叠加规则
    int actual_param1 = 1;
    int& actual_param2 = actual_param1;
    int&& actual_param3 = move(actual_param1);
    FuncRule1(actual_param2);
    IsRightReference(actual_param3);  // 左值
    IsRightReference(forward<int>(actual_param3));  // 右值

    // 在函数模板中，可以帮右值绑定到左值
    FuncRule2(forward<int>(actual_param3));

    FuncRule3(actual_param2);
    FuncRule4(forward<int>(actual_param3));
    return 0;
}
