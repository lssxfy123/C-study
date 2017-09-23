// Copyright 2017.刘珅珅
// author：刘珅珅
// 随机数
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    // 每次运行程序
    // 得到的随机数不一样
    random_device rd;

    // 引擎
    // create default engine as source
    // of randomness
    default_random_engine dre(rd());

    // 线性分布
    // use engine to generate integral
    // numbers between 10 and 20(both included)
    uniform_int_distribution<int> di(10, 20);
    for (int i = 0; i < 20; ++i)
    {
        cout << di(dre) << " ";
    }
    cout << endl;
    cout << endl;

    // 线性分布
    // use engine to generate floating-point
    // numbers between 10.0 and 20.0
    // (10.0 included, 20.0 not included)
    uniform_real_distribution<double> dr(10, 20);
    for (int i = 0; i < 8; ++i)
    {
        cout << dr(dre) << " ";
    }
    cout << endl;
    cout << endl;

    // 洗牌
    // use engine to shuffle elements
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(v.begin(), v.end(), dre);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // 两次洗牌结果不同
    shuffle(v.begin(), v.end(), dre);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
