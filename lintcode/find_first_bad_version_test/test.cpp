// Copyright 2019.���|�|
// author�����|�|
// ��һ������Ĵ���汾
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// ���lintcode���ṩ�ĺ���
bool isBadVersion(int k)
{
    return false;
}

int findFirstBadVersion(int n) {
    // write your code here
    int start = 1;  // �汾�Ŵ�1��ʼ
    int end = n;

    while (start + 1 < end)  // ��Ҫ�Ǳ���start = end - 1��start = end��ɵ���ѭ������
    {
        int middle = start + (end - start) / 2;
        if (isBadVersion(middle))
        {
            // ����ֱ������ѭ����Ҫ���ҵ�1������İ汾��
            end = middle;
        }
        else
        {
            start = middle;
        }
    }

    if (isBadVersion(start))
    {
        return start;
    }

    return end;
}

int main(int argc, char* argv[])
{
    return 0;
}
