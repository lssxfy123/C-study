// Copyright 2018.���|�|
// author�����|�|
// O(1)ʱ����n�Ƿ�Ϊ2���ݴ�
#include <iostream>
#include "../../include/print.hpp"
using namespace std;

bool checkPowerOf2(int n) {
    // write your code here
    if (n <= 0)
    {
        return false;
    }

    // ���nΪ2���ݴΣ������ڶ�������ֻ��1λΪ1������Ϊ0
    // n - 1�ͻᷢ����λ���󣬵���ԭ��Ϊ1��λ���0��
    // n & (n - 1)�϶�Ϊ0
    return (n & (n - 1)) == 0;

}

int main(int argc, char* argv[])
{
    return 0;
}
