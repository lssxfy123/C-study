// Copyright 2019.刘珅珅
// author：刘珅珅
// 两个排序数组的中位数
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int findPeak(vector<int> &A) {
    // write your code here
    if (A.size() < 3)
    {
        return -1;
    }

    // A中的第1个元素和最后一个元素肯定不是Peak
    // 数组A的特点A[0]<A[1]和A[n-2]>A[n-1]，则肯定存在Peak
    // 原因是：相邻元素不同，则相邻元素肯定能分出大小，如果不存在Peak
    // 则A[2]必须大于A[1]，否则A[1]就是Peak，并且从A[2]开始元素必须单调上升
    // 否则出现下降的位置k的前一个位置的元素就是Peak，因为会出现A[k-1]>A[k-2]
    // 并且A[k-1]>A[k]。又因为A[n-2]>A[n-1]，显然不满足从A[2]开始单调上升
    int start = 1;
    int end = A.size() - 2;

    while (start + 1 < end)
    {
        int middle = start + (end - start) / 2;
        if (A[middle] > A[middle - 1] && A[middle] > A[middle + 1])
        {
            return middle;
        }
        // 下面两个判断其实就是构建出一个新的数组并且满足A的特点
        else if (A[middle] > A[middle - 1])
        {
            // A[middle] < A[middle + 1]
            // start=middle+1，这样[middle,start,...end,end+1]构成的数组tmp
            // 仍然满足数组A的特点，即tmp[0]<tmp[1]和 tmp[k-2]>tmp[k-1]，k为tmp的长度
            // 这样tmp中肯定存在Peak
            start = middle + 1;
        }
        else
        {
            // A[middle-1]>A[middle]，这样新构建的数组tmp满足tmp[k-2]>tmp[k-1]
            // 和tmp[0]<tmp[1]
            end = middle - 1;
        }
    }

    // 数组A肯定存在Peak，如果上述的while循环没有返回
    // 则说明Peak就是A[start]或A[end]
    if (A[start] > A[end])
    {
        return start;
    }

    return end;
}

int main(int argc, char* argv[])
{
    vector<int> A{ 1, 2, 1, 3, 4, 5, 7, 6 };
    cout << findPeak(A) << endl;
    return 0;
}
