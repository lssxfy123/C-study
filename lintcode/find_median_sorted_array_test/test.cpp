// Copyright 2019.���|�|
// author�����|�|
// ���������������λ��
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

// �������������kСԪ��kMin�������������鶼����������
// ���A[k/2-1]>B[k/2-1]�����������kСԪ�ؿ϶�����B��ǰk/2��Ԫ����
// ��Ϊ�����kСԪ����B��ǰk/2��Ԫ���У������kMin<=B[k/2-1]��
// ͬʱ��ʾ��������ǰk-1СԪ����A�б����������k/2������ζ��kMin>=A[k/2-1]
// ��ʾ����ì�ܵģ���֮���A[k/2-1]<B[k/2-1]�������kMin�϶�����A��ǰk/2��Ԫ����
// �����Ϳ����޳���A��B��ǰk/2��Ԫ�أ�Ȼ����ʣ�µ���������ĵ�k-k/2СԪ��
double findKth(vector<int> &A, vector<int> &B, int A_start, int B_start, int k)
{
    // ��������ĵ�kСԪ�ز���A��
    if (A_start >= A.size())
    {
        return B[B_start + k - 1];
    }

    // ��������ĵ�kСԪ�ز���B��
    if (B_start >= B.size())
    {
        return A[A_start + k - 1];
    }

    if (k == 1)
    {
        return min(A[A_start], B[B_start]);
    }

    // A_start + k / 2 - 1��ʾ��A_start��ʼ�ĵ�k/2��Ԫ��
    int A_k = A_start + k / 2 - 1 >= A.size() ? INT_MAX : A[A_start + k / 2 - 1];
    int B_k = B_start + k / 2 - 1 >= B.size() ? INT_MAX : B[B_start + k / 2 - 1];
    if (A_k < B_k)
    {
        // �޳���A��A_start+k/2��Ԫ�أ���ʼԪ��ΪA_start+k/2
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

    if (total & 1)  // ����
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
