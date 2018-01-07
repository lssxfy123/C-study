// Copyright 2017.刘珅珅
// author：刘珅珅
// 排序的比较
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "../include/Clock.hpp"
using namespace std;
using namespace chrono;

int main(int argc, char* argv[])
{
    Clock main_clock(MillSecond);
    main_clock.Start();
    const int count = 1000000;
    vector<int> sort_array;
    sort_array.reserve(count);

    // 每次运行程序
    // 得到的随机数不一样
    random_device rd;

    // 引擎
    // create default engine as source
    // of randomness
    default_random_engine dre(rd());

    // 线性分布
    // use engine to generate integral
    uniform_int_distribution<int> di(1, count);
    for (int i = 0; i < count; ++i)
    {
        sort_array.push_back(di(dre));
    }

    Clock sort_clock(MillSecond);
    sort_clock.Start();
    sort(sort_array.begin(), sort_array.end());
    sort_clock.End();
    main_clock.End();
    cout << "sort use milliseconds " << sort_clock.Duration() << endl;

    cout << "main use milliseconds " << main_clock.Duration() << endl;
    return 0;
}
