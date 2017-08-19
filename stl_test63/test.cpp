// Copyright 2017.刘珅珅
// author：刘珅珅
// lambda vs binder
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    auto plus10 = [](int i) {
        return i + 10;
    };

    cout << "+10:    " << plus10(7) << endl;

    auto plus10time2 = [](int i) {
        return (i + 10) * 2;
    };
    cout << "+10 * 2:     " << plus10time2(7) << endl;

    auto pow3 = [](int i) {
        return i * i * i;
    };

    cout << "x * x * x:   " << pow3(7) << endl;

    auto inversDivide = [](double d1, double d2) {
        return d2 / d1;
    };
    cout << "invdiv:   " << inversDivide(49, 7) << endl;

    // Lambda对比带状态的function object
    vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8};
    long sum = 0;
    for_each(coll.begin(), coll.end(), [&sum](int elem) {
        sum += elem;
    });
    double mv = static_cast<double>(sum)
        / static_cast<double>(coll.size());
    cout << "mean value:   " << mv << endl;

    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintElements(coll1, "coll1:    ");
    int count = 0;
    // Lambda使用mutable
    // count以by value形式
    // 但是可以在Lambda表达式内部
    // 修改其值，作用域以外没有效果
    list<int>::iterator pos
        = remove_if(coll1.begin(), coll1.end(),
            [count](int) mutable {
        return ++count == 3;
    });
    cout << "count:   " << count << endl;
    coll1.erase(pos, coll1.end());
    PrintElements(coll1, "3rd removed:  ");
    return 0;
}
