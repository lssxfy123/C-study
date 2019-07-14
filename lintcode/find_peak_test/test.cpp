// Copyright 2019.���|�|
// author�����|�|
// ���������������λ��
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

    // A�еĵ�1��Ԫ�غ����һ��Ԫ�ؿ϶�����Peak
    // ����A���ص�A[0]<A[1]��A[n-2]>A[n-1]����϶�����Peak
    // ԭ���ǣ�����Ԫ�ز�ͬ��������Ԫ�ؿ϶��ֳܷ���С�����������Peak
    // ��A[2]�������A[1]������A[1]����Peak�����Ҵ�A[2]��ʼԪ�ر��뵥������
    // ��������½���λ��k��ǰһ��λ�õ�Ԫ�ؾ���Peak����Ϊ�����A[k-1]>A[k-2]
    // ����A[k-1]>A[k]������ΪA[n-2]>A[n-1]����Ȼ�������A[2]��ʼ��������
    int start = 1;
    int end = A.size() - 2;

    while (start + 1 < end)
    {
        int middle = start + (end - start) / 2;
        if (A[middle] > A[middle - 1] && A[middle] > A[middle + 1])
        {
            return middle;
        }
        // ���������ж���ʵ���ǹ�����һ���µ����鲢������A���ص�
        else if (A[middle] > A[middle - 1])
        {
            // A[middle] < A[middle + 1]
            // start=middle+1������[middle,start,...end,end+1]���ɵ�����tmp
            // ��Ȼ��������A���ص㣬��tmp[0]<tmp[1]�� tmp[k-2]>tmp[k-1]��kΪtmp�ĳ���
            // ����tmp�п϶�����Peak
            start = middle + 1;
        }
        else
        {
            // A[middle-1]>A[middle]�������¹���������tmp����tmp[k-2]>tmp[k-1]
            // ��tmp[0]<tmp[1]
            end = middle - 1;
        }
    }

    // ����A�϶�����Peak�����������whileѭ��û�з���
    // ��˵��Peak����A[start]��A[end]
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
