// Copyright 2018.���|�|
// author�����|�|
// ���Ҳ���λ��
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int singleNumber(vector<int> &A) {
    // write your code here
    if (A.size() == 0)
    {
        return -1;
    }
    int result = 0;

    // �����������ɽ���
    // ������ͬ���������Ϊ0
    // �������ɽ���
    // (2^1^5^4^2^4^1) = ((2^2)^(1^1)^(4^4)^5) = (0^0^0^5) = 5
    for (int i = 0; i < A.size(); ++i)
    {
        result ^= A[i];
    }
    return result;
}

int main(int argc, char* argv[])
{
    return 0;
}
