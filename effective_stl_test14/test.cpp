// Copyright 2017.刘珅珅
// author：刘珅珅
// accumulate
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<float> vf{ 1.2f, 3.5f, 5.7f };
    
    // 容器元素的乘积
    // 1.0f为initValue，multiplies<float>()为指定的函数op
    // initValue op a1 op a2 op a3...
    float product = accumulate(vf.begin(), vf.end(), 1.0f, multiplies<float>());

    cout << "Product : " << product << endl;
    return 0;
}
