// Copyright 2017.���|�|
// author�����|�|
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
    
    // ����Ԫ�صĳ˻�
    // 1.0fΪinitValue��multiplies<float>()Ϊָ���ĺ���op
    // initValue op a1 op a2 op a3...
    float product = accumulate(vf.begin(), vf.end(), 1.0f, multiplies<float>());

    cout << "Product : " << product << endl;
    return 0;
}
