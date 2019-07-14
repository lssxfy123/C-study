// Copyright 2019.刘珅珅
// author：刘珅珅
// 两个排序数组的中位数
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// 查找两个数组第k小元素kMin，由于两个数组都是升序排列
// 如果A[k/2-1]>B[k/2-1]，两个数组第k小元素肯定不在B的前k/2个元素中
// 因为如果第k小元素在B的前k/2个元素中，则表明kMin<=B[k/2-1]，
// 同时表示两个数组前k-1小元素中A中必须包含至少k/2个，意味着kMin>=A[k/2-1]
// 显示这是矛盾的；反之如果A[k/2-1]<B[k/2-1]，则表明kMin肯定不在A的前k/2个元素中
// 这样就可以剔除掉A或B的前k/2个元素，然后求剩下的两个数组的第k-k/2小元素
double findKth(vector<int> &A, vector<int> &B, int A_start, int B_start, int k)
{
    // 两个数组的第k小元素不在A中
    if (A_start >= A.size())
    {
        return B[B_start + k - 1];
    }

    // 两个数组的第k小元素不在B中
    if (B_start >= B.size())
    {
        return A[A_start + k - 1];
    }

    if (k == 1)
    {
        return min(A[A_start], B[B_start]);
    }

    // A_start + k / 2 - 1表示从A_start开始的第k/2个元素
    int A_k = A_start + k / 2 - 1 >= A.size() ? INT_MAX : A[A_start + k / 2 - 1];
    int B_k = B_start + k / 2 - 1 >= B.size() ? INT_MAX : B[B_start + k / 2 - 1];
    if (A_k < B_k)
    {
        // 剔除掉A的A_start+k/2个元素，起始元素为A_start+k/2
        return findKth(A, B, A_start + k / 2, B_start, k - k / 2);
    }
    else
    {
        return findKth(A, B, A_start, B_start + k / 2, k - k / 2);
    }
}

double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    // write your code here
    int total = A.size() + B.size();
    if (total == 0)
    {
        return 0.0;
    }

    if (total & 1)  // 奇数
    {
        return findKth(A, B, 0, 0, total / 2 + 1);
    }
    else
    {
        return (findKth(A, B, 0, 0, total / 2) + findKth(A, B, 0, 0, total / 2 + 1)) / 2.0;
    }
    return 0.0;
}

int main(int argc, char* argv[])
{
    vector<int> A{ 1, 2, 3, 4, 5 };
    vector<int> B{ 2, 3, 4, 5 };
    cout << findMedianSortedArrays(A, B) << endl;
    return 0;
}
