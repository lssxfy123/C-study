// Copyright 2017.刘珅珅
// author：刘珅珅
// lambda表达式2
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // 可变lambda
    // 值捕获的lambda一般不可以修改捕获的值
    // 但可以通过添加关键字mutable来修改捕获的值
    size_t v1 = 42;
    auto f1 = [v1]() mutable {return ++v1; };
    v1 = 0;
    auto j = f1();  // j = 43


    // ->int显示指定lambda的返回类型
    auto f3 = [](int i) ->int {
        if (i > 0)
            return i;
        else
            return -i;
    };

    auto k = f3(3);
    return 0;
}
