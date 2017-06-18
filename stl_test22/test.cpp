// Copyright 2017.刘珅珅
// author：刘珅珅
// 函数外覆器：wrapper
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void Func(int x, int y)
{
    cout << "function x: " << x << " y: " << y << endl;
}

class A {
private:
    // C++11允许非静态成员在其声明处进行初始化
    int i = 0;

public:
    void MemberFunc(int x, int y) const
    {
        cout << "member function x: " << x << " y: " << y << endl;
    }
};

int main(int argc, char* argv[])
{
    vector<function<void(int, int)>> tasks;
    tasks.push_back(Func);
    tasks.push_back([](int x, int y) {
        cout << "lambda x: " << x << " y: " << y << endl;
    });

    for (function<void(int, int)> f : tasks)
    {
        f(33, 66);
    }

    // 类成员函数的外覆器
    function<void(int, int)> member_func_wrapper;
    A a;
    member_func_wrapper = bind(&A::MemberFunc, a, std::placeholders::_1, std::placeholders::_2);
    member_func_wrapper(33, 66);
    return 0;
}
